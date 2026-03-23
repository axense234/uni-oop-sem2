#include "Movie.tests.h"

#include <assert.h>

MovieTests::MovieTests()
{
    this->movie = Movie{1, "Title", ACTION, 1999, 20, "https://youtube.com"};
}

void MovieTests::testProperties()
{
    assert(this->movie.getId() == 1);
    assert(this->movie.getTitle() == "Title");
    assert(this->movie.getGenre() == ACTION);
    assert(this->movie.getYearOfRelease() == 1999);
    assert(this->movie.getNumberOfLikes() == 20);
    assert(this->movie.getTrailer() == "https://youtube.com");
}