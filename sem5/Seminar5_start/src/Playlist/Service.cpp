#include "Service.h"
#include <algorithm>
#include "FilePlaylist.h"
#include "RepositoryExceptions.h"

using namespace std;

void Service::addSongToRepository(const std::string &artist, const std::string &title, double minutes, double seconds, const std::string &source)
{
	Song s{artist, title, Duration{minutes, seconds}, source};
	this->validator.validate(s);
	this->repo.addSong(s);

	std::unique_ptr<Action> undoAction = std::make_unique<ActionAdd>(s, this->repo);
	this->undo.push(std::move(undoAction));
}

void Service::removeSongFromRepository(const std::string &artist, const std::string &title)
{
	Song s = this->repo.findByArtistAndTitle(artist, title);
	this->repo.removeSong(s);

	std::unique_ptr<Action> undoAction = std::make_unique<ActionRemove>(s, this->repo);
	this->undo.push(std::move(undoAction));
}

void Service::updateSongFromRepository(const std::string &artist, const std::string &title, const Song &newSong)
{
	Song s = this->repo.findByArtistAndTitle(artist, title);
	this->repo.updateSong(s.getArtist(), s.getTitle(), newSong);

	std::unique_ptr<Action> undoAction = std::make_unique<ActionUpdate>(s, newSong, this->repo);
	this->undo.push(std::move(undoAction));
}

void Service::addSongToPlaylist(const Song &song)
{
	if (this->playList == nullptr)
		return;
	this->playList->add(song);
}

void Service::addAllSongsByArtistToPlaylist(const std::string &artist)
{
	vector<Song> songs = this->repo.getSongs();
	int nSongs = static_cast<int>(count_if(songs.begin(), songs.end(),
										   [artist](const Song &s)
										   {
											   return s.getArtist() == artist;
										   }));

	vector<Song> songsByArtist(nSongs);
	copy_if(songs.begin(), songs.end(), songsByArtist.begin(),
			[artist](const Song &s)
			{
				return s.getArtist() == artist;
			});

	for (auto s : songsByArtist)
		this->playList->add(s);
}

void Service::startPlaylist()
{
	if (this->playList == nullptr)
		return;
	this->playList->play();
}

void Service::nextSongPlaylist()
{
	if (this->playList == nullptr)
		return;
	this->playList->next();
}

void Service::savePlaylist(const std::string &filename)
{
	if (this->playList == nullptr)
		return;

	this->playList->setFilename(filename);
	this->playList->writeToFile();
}

void Service::openPlaylist() const
{
	if (this->playList == nullptr)
		return;

	this->playList->displayPlaylist();
}

void Service::undoOperation()
{

	if (this->undo.size() == 0)
	{
		throw std::exception();
	}

	std::unique_ptr<Action> undoAction = std::move(this->undo.top());

	undoAction->executeUndo();

	this->redo.push(std::move(undoAction));
	this->undo.pop();
}

void Service::redoOperation()
{
	if (this->redo.size() == 0)
	{
		throw std::exception();
	}

	std::unique_ptr<Action> redoAction = std::move(this->redo.top());

	redoAction->executeRedo();

	this->undo.push(std::move(redoAction));
	this->redo.pop();
}