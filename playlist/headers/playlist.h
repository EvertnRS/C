#ifndef PLAYLIST_H
#define PLAYLIST_H

typedef struct Playlist
{
    char titulo[100];
    char artista[100];
    struct Playlist *proxima;
} Playlist;

#endif // WELCOME_H
