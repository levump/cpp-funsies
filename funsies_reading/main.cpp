#include <fstream>
#include <iostream>
#include <vector>
#include <iterator>
#include <deque>
#include <algorithm>
#include <numeric>
#include <string>

struct line_fun{
	private:
		std::string m_line;

	public:
		operator std::string const& () const {return m_line;}
friend std::istream& operator>> (std::istream& in, line_fun& line)
{
	return std::getline(in, line.m_line, '.');
}
};

void dotify(std::deque<std::string>& lines)
{
	std::transform(std::begin(lines), std::end(lines), std::begin(lines), [](const auto& s){return s + ".";});
}
//try to find a better solution
void ltrim(std::deque<std::string>& lines)
{
	std::transform(std::begin(lines), std::end(lines), std::begin(lines), [](auto &s){
																																						return std::string(std::begin(s) + 1, std::end(s));
																																						});
}

int main(){
	std::ifstream in("./loremipsum");
	std::deque<std::string> line_file{std::istream_iterator<line_fun>(in), std::istream_iterator<line_fun>()};
	//try to fix this
	/*std::vector<std::string> correct_line_file = std::accumulate(std::begin(line_file), 
																															 std::end(line_file), 
   	              															  					   std::vector<std::string>(), 
       																												 [](std::vector<std::string>& acc, auto& x){
																																	auto i = std::accumulate(std::begin(x),
																																													 std::end(x),
																																													 std::string(),
																																													 [](std::string& acc, auto& c){
																																																if(c == '.'){
																																																		acc += c;
																																																		acc += "\n";
																																																}
																																																else	 																																																																																													acc += c;
																																																		return acc;
																																													 }); 
																																	acc.push_back(i);
																																	return acc;																															
																																});*/
	dotify(line_file);
	ltrim(line_file);
	std::copy(std::cbegin(line_file), std::cend(line_file), std::ostream_iterator<std::string>(std::cout, "\n"));
	std::cout << "line count: " << line_file.size() << std::endl;	
	return 0;
}
