#include <iostream>
#include <exception>

#include "../tests/domain/Movie.tests.h"
#include "../tests/domain/DynamicVector.tests.h"
#include "../tests/services/Movie.services.tests.h"
#include "../tests/services/Playlist.services.tests.h"
#include "../tests/repo/Memory.repo.tests.h"
#include "../tests/helpers/Helpers.tests.h"

using namespace std;

int main()
{

    MovieTests movieTests;
    movieTests.runAllMovieTests();

    DynamicVectorTests dynamicVectorTests;
    dynamicVectorTests.runAllDynamicVectorTests();

    MemoryRepoTests memoryRepoTests;
    memoryRepoTests.runAllMemoryRepoTests();

    MovieServicesTests movieServicesTests;
    movieServicesTests.runAllMovieServicesTests();

    PlaylistServicesTests playlistServicesTests;
    playlistServicesTests.runAllPlaylistServicesTests();

    HelpersTests helpersTests;
    helpersTests.runAllHelpersTests();

    return 0;
}
