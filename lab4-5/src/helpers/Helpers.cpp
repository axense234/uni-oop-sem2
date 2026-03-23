#include "Helpers.h"

#include <string>
#include <exception>

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