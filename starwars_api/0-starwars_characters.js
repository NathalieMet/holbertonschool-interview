#!/usr/bin/node
const request = require('request');

const movieId = process.argv[2];


if (!movieId) {
	console.error('Usage: node script.js <movie>');
	process.exit(1);
}

const url = `https://swapi-api.hbtn.io/api/films/${movieId}`;

request(url, (error, response, body) => {
  if (error) {
    console.error('Error:', error.message);
    return;
  }

  if (response.statusCode !== 200) {
    console.error('Failed to retrieve data. Status code:', response.statusCode);
    return;
  }

  try {
    const movieData = JSON.parse(body);
    const characters = movieData.characters;
	characters.forEach((characterUrl) => {
		request(characterUrl, (charError, charResponse, charBody) => {
		  if (charError) {
			console.error('Error:', charError.message);
			return;
		  }

		  if (charResponse.statusCode === 200) {
			const characterData = JSON.parse(charBody);
			console.log(characterData.name);
		  }
		});
	  });
	} catch (parseError) {
	  console.error('Error parsing JSON:', parseError.message);
	}
  });
