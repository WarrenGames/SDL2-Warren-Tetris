#ifndef LOAD_TEXT_FILE_LINE_H
#define LOAD_TEXT_FILE_LINE_H

#include <vector>
#include <string>
#include <iosfwd>

class LogFile;

class TextsBlocks
{
private:
	const std::string errorString;
	std::vector<std::string> texts;
	bool isLoadingPerfect;
	
public:
	explicit TextsBlocks(LogFile& log, const std::string& filePath);
	explicit TextsBlocks(LogFile& log, const std::string& filePath, unsigned expectedStringsNumber);
	explicit TextsBlocks(std::string& logString, const std::string& filePath, unsigned expectedStringsNumber);
	explicit TextsBlocks(std::string& logString, const std::string& filePath);
	~TextsBlocks() = default;
	TextsBlocks( const TextsBlocks& ) = delete;
	TextsBlocks& operator= ( const TextsBlocks& ) = delete;
	TextsBlocks( TextsBlocks&& ) = default;
	TextsBlocks& operator= ( TextsBlocks&& ) = default;
	
	operator bool () const;
	bool wasReadingPerfect() const;
	const std::vector<std::string>& getTexts() const;
	const std::string& operator[](size_t lineNumber) const;
	size_t size() const;
	
	const std::vector<std::string>::const_iterator begin() const;
	const std::vector<std::string>::const_iterator end() const;
	std::vector<std::string>::iterator begin();
	std::vector<std::string>::iterator end();
	
private:
	void loadTextLines(std::ifstream& textFile);
};

#endif //LOAD_TEXT_FILE_LINE_H