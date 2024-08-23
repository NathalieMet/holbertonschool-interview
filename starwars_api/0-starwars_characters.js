#!/usr/bin/node
const request = require('request');
const util = require('util');

const requestPromise = util.promisify(request);

async function getCharacterName (url) {
  try {
    const response = await requestPromise(url);
    const characterData = JSON.parse(response.body);
    return characterData.name;
  } catch (error) {
    console.error('Error fetching character:', error.message);
  }
}

async function printMovieCharacters (movieId) {
  if (!movieId) {
    console.error('Usage: node script.js <movie>');
    process.exit(1);
  }

  const url = `https://swapi-api.hbtn.io/api/films/${movieId}`;

  try {
    const response = await requestPromise(url);
    const movieData = JSON.parse(response.body);
    const characters = movieData.characters;

    for (const characterUrl of characters) {
      const name = await getCharacterName(characterUrl);
      if (name) {
        console.log(name);
      }
    }
  } catch (error) {
    console.error('Error fetching movie data:', error.message);
  }
}

const movieId = process.argv[2];
printMovieCharacters(movieId);
