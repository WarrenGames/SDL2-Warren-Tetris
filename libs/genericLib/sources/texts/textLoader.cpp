#include "texts/textLoader.h"
#include "logging/logFile.h"
#include <cassert>

TextsBlocks::TextsBlocks(LogFile& log, const std::string& filePath):
	errorString{"error"},
	isLoadingPerfect{true}
{
	if( std::ifstream languageFile{filePath} )
	{
		loadTextLines(languageFile);
	}
	else{
		isLoadingPerfect = false;
		log.wrFileOpeningError(filePath, "language text file");
	}
}

TextsBlocks::TextsBlocks(LogFile& log, const std::string& filePath, unsigned expectedStringNumber):
	errorString{"error"},
	isLoadingPerfect{true}
{
	if( std::ifstream languageFile{filePath} )
	{
		loadTextLines(languageFile);
		if( texts.size() != expectedStringNumber )
		{
			log.wrPrefixAndSimpleMessage("loading lang file '" + filePath + "' failed because size: " + std::to_string(texts.size() )
												+ " is different from expected " + std::to_string(expectedStringNumber) + " texts");
			isLoadingPerfect = false;
		}
	}
	else{
		log.wrFileOpeningError(filePath, "load language text file");
		isLoadingPerfect = false;
	}
}

TextsBlocks::TextsBlocks(std::string& logString, const std::string& filePath, unsigned expectedStringsNumber):
	errorString{"error"},
	isLoadingPerfect{true}
{
	if( std::ifstream languageFile{filePath} )
	{
		loadTextLines(languageFile);
		if( texts.size() != expectedStringsNumber )
		{
			logString = std::string{"Error: loading lang file '" + filePath + "' failed because size: " + std::to_string(texts.size() )
										+ " is different from expected " + std::to_string(expectedStringsNumber) + " texts"};
			isLoadingPerfect = false;
		}
	}
	else{
		logString = "Error: couldn't open '" + filePath + "' file in order to load language text file.";
		isLoadingPerfect = false;
	}
}

TextsBlocks::TextsBlocks(std::string& logString, const std::string& filePath):
	errorString{"error"},
	isLoadingPerfect{true}
{
	if( std::ifstream languageFile{filePath} )
	{
		loadTextLines(languageFile);
	}
	else{
		logString = "Error: couldn't open '" + filePath + "' file in order to load language text file.";
		isLoadingPerfect = false;
	}
}

TextsBlocks::operator bool() const
{
	return isLoadingPerfect;
}

bool TextsBlocks::wasReadingPerfect() const
{
	return isLoadingPerfect;
}

const std::vector<std::string>& TextsBlocks::getTexts() const
{
	return texts;
}

const std::string& TextsBlocks::operator[](size_t lineNumber) const
{
	if( lineNumber < texts.size() )
	{
		return texts[lineNumber];
	}
	else{
		return errorString;
	}
}

size_t TextsBlocks::size() const
{
	return texts.size();
}

const std::vector<std::string>::const_iterator TextsBlocks::begin() const
{
	return texts.cbegin();
}

const std::vector<std::string>::const_iterator TextsBlocks::end() const
{
	return texts.cend();
}

std::vector<std::string>::iterator TextsBlocks::begin()
{
	return texts.begin();
}

std::vector<std::string>::iterator TextsBlocks::end()
{
	return texts.end();
}

void TextsBlocks::loadTextLines(std::ifstream& textFile)
{
	std::string fileLine;
	while(std::getline(textFile, fileLine) )
	{
		if( fileLine[0] != '#' )
		{
			texts.emplace_back(fileLine);
		}
	}
}