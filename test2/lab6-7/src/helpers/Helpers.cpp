#include "Helpers.h"

#include <string>
#include <exception>
#include <vector>
#include <cstdlib>

void Helpers::insertTenMovieEntriesInTheDatabase(MovieServices &services)
{
    std::vector<Movie> movies = {
        Movie{1, "The Shawshank Redemption", HORROR, 1299, 20, "https://www.youtube.com/watch?v=PLl99DlL6b4&pp=ygUgVGhlIFNoYXdzaGFuayBSZWRlbXB0aW9uIHRyYWlsZXI%3D"},
        Movie{2, "The Godfather", ADVENTURE, 1299, 20, "https://www.youtube.com/watch?v=UaVTIH8mujA&pp=ygUVdGhlIGdvZGZhdGhlciB0cmFpbGVy"},
        Movie{3, "Pulp Fiction", FAMILY, 1299, 20, "https://www.youtube.com/watch?v=s7EdQ4FqbhY&pp=ygUUcHVscCBmaWN0aW9uIHRyYWlsZXI%3D"},
        Movie{4, "Inception", COMEDY, 1299, 20, "https://www.youtube.com/watch?v=YoHD9XEInc0&pp=ygURaW5jZXB0aW9uIHRyYWlsZXI%3D"},
        Movie{5, "The Dark Knight", ADVENTURE, 1299, 20, "https://www.youtube.com/watch?v=EXeTwQWrcwY&pp=ygUXdGhlIGRhcmsga25pZ2h0IHRyYWlsZXI%3D"},
        Movie{6, "Forrest Gump", HORROR, 1299, 20, "https://www.youtube.com/watch?v=bLvqoHBptjg&pp=ygUTRm9yZXN0IGd1bXAgdHJhaWxlcg%3D%3D"},
        Movie{7, "Fight Club", SCIFI, 1299, 20, "https://www.youtube.com/watch?v=qtRKdVHc-cE&pp=ygUSZmlnaHQgY2x1YiB0cmFpZWxy"},
        Movie{8, "The Matrix", HISTORY, 1299, 20, "https://www.youtube.com/watch?v=vKQi3bBA1y8&pp=ygUSdGhlIG1hdHJpeCB0cmFpbGVy"},
        Movie{9, "Goodfellas", HORROR, 1299, 20, "https://www.youtube.com/watch?v=2ilzidi_J8Q&pp=ygUSZ29vZGZlbGxhcyB0cmFpbGVy"},
        Movie{10, "Interstellar", ADVENTURE, 1299, 20, "https://www.youtube.com/watch?v=zSWdZVtXT7E&pp=ygUUSW50ZXJzdGVsbGFyIHRyYWlsZXI%3D"}};

    for (const auto &movie : movies)
    {
        services.addMovie(movie);
    }
}

void Helpers::openURL(const std::string &url)
{
    std::string command = "cmd.exe /c start chrome --incognito " + url;
    std::system(command.c_str());
}

void Helpers::openFileInBrowser(const std::string &file)
{
    std::string command = "cmd.exe /c start " + file;
    system(command.c_str());
}

void Helpers::openFileInNotepad(const std::string &file)
{
    std::string command = "cmd.exe /c notepad.exe " + file;
    system(command.c_str());
}

MovieGenre Helpers::convertGivenStringToMovieGenre(const std::string &raw)
{
    if ((raw == "ACTION"))
    {
        return ACTION;
    }
    else if (raw == "ADVENTURE")
    {
        return ADVENTURE;
    }
    else if (raw == "ANIMATION")
    {
        return ANIMATION;
    }
    else if (raw == "BIOGRAPHY")
    {
        return BIOGRAPHY;
    }
    else if (raw == "COMEDY")
    {
        return COMEDY;
    }
    else if (raw == "CRIME")
    {
        return CRIME;
    }
    else if (raw == "DOCUMENTARY")
    {
        return DOCUMENTARY;
    }
    else if (raw == "DRAMA")
    {
        return DRAMA;
    }
    else if (raw == "FAMILY")
    {
        return FAMILY;
    }
    else if (raw == "FANTASY")
    {
        return FANTASY;
    }
    else if (raw == "HISTORY")
    {
        return HISTORY;
    }
    else if (raw == "HORROR")
    {
        return HORROR;
    }
    else if (raw == "MUSIC")
    {
        return MUSIC;
    }
    else if (raw == "MYSTERY")
    {
        return MYSTERY;
    }
    else if (raw == "ROMANCE")
    {
        return ROMANCE;
    }
    else if (raw == "SCIFI")
    {
        return SCIFI;
    }
    else if (raw == "SPORT")
    {
        return SPORT;
    }
    else if (raw == "WAR")
    {
        return WAR;
    }
    else if (raw == "WESTERN")
    {
        return WESTERN;
    }

    throw std::exception();
}

std::string Helpers::convertGivenMovieGenreToString(MovieGenre genre)
{
    if ((genre == ACTION))
    {
        return "ACTION";
    }
    else if (genre == ADVENTURE)
    {
        return "ADVENTURE";
    }
    else if (genre == ANIMATION)
    {
        return "ANIMATION";
    }
    else if (genre == BIOGRAPHY)
    {
        return "BIOGRAPHY";
    }
    else if (genre == COMEDY)
    {
        return "COMEDY";
    }
    else if (genre == CRIME)
    {
        return "CRIME";
    }
    else if (genre == DOCUMENTARY)
    {
        return "DOCUMENTARY";
    }
    else if (genre == DRAMA)
    {
        return "DRAMA";
    }
    else if (genre == FAMILY)
    {
        return "FAMILY";
    }
    else if (genre == FANTASY)
    {
        return "FANTASY";
    }
    else if (genre == HISTORY)
    {
        return "HISTORY";
    }
    else if (genre == HORROR)
    {
        return "HORROR";
    }
    else if (genre == MUSIC)
    {
        return "MUSIC";
    }
    else if (genre == MYSTERY)
    {
        return "MYSTERY";
    }
    else if (genre == ROMANCE)
    {
        return "ROMANCE";
    }
    else if (genre == SCIFI)
    {
        return "SCIFI";
    }
    else if (genre == SPORT)
    {
        return "SPORT";
    }
    else if (genre == WAR)
    {
        return "WAR";
    }
    else if (genre == WESTERN)
    {
        return "WESTERN";
    }

    throw std::exception();
}
