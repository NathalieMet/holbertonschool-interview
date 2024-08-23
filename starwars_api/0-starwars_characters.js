#!/usr/bin/node
const request = require('request-promise');

async function getCharacterName(url) {
    try {
        const body = await request(url);
        const characterData = JSON.parse(body);
        return characterData.name;
    } catch (error) {
        console.error('Error:', error.message);
    }
}

async function printMovieCharacters(movieId) {
    if (!movieId) {
        console.error('Usage: node script.js <movie>');
        process.exit(1);
    }

    const url = `https://swapi-api.hbtn.io/api/films/${movieId}`;

    try {
        const body = await request(url);
        const movieData = JSON.parse(body);
        const characters = movieData.characters;

        for (const characterUrl of characters) {
            const name = await getCharacterName(characterUrl);
            if (name) {
                console.log(name);
            }
        }
    } catch (error) {
        console.error('Error:', error.message);
    }
}

const movieId = process.argv[2];
printMovieCharacters(movieId);
