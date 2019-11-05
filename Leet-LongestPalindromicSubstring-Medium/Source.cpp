///////////////////////////////////////////////////
//Source:	Shrenik Daga, Syracuse University   //
//			shdaga@syr.edu						//
/////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>

/*
This is basically using brute force so O(n^2)
*/
bool isPalindrome(std::string subString)
{
	if (subString.size() == 0)
		return false;
	if (subString.size() == 1)
		return true;

	int left = 0;
	int right = subString.size() - 1;

	while (left < right)
	{
		if (subString[left] == subString[right])
		{
			++left; --right;
		}
		else
		{
			return false;
		}
	}
	return true;
}

std::string longestPalindrome(std::string s)
{
	if (s.size() == 0)
		return "";

	if (s.size() == 1)
		return s;

	int left = 0;
	int right = 0;
	int offset=0;// = s.size() % 2 == 0 ? 1 : 0;
	int longestLeft = 0, longestRight = 0;

	while (left < s.size() && right < s.size())
	{
		if (isPalindrome(s.substr(left, right - left)))
		{
			if (longestRight - longestLeft < right - left)
			{
				longestLeft = left;
				longestRight = right;
				//longestRight += offset;
			}
				++right;
		}
		else
		{
			++right;
		}

		if (right == s.size())
		{
			++left;
			right = left;
		}
	}
	if (longestRight - longestLeft + 1 == s.size())
		offset = 1;
	return s.substr(longestLeft,longestRight-longestLeft+offset);
}

/*
Manacher's algorithm
	string longestPalindrome(string s) {
	if (s.empty()) return "";
	string prep = "#";
	for (auto ch : s) { prep += ch; prep += "#";}
	const int size_p = prep.size();
	vector<int> dp(size_p, 0);
	int center = 0, bCur = 0;
	for (int i = 0; i < size_p; i++) {
		int mirror = center - (i - center);
		dp[i] = bCur <= i ? 0 : min(bCur - i, dp[mirror]);
		int start = i - dp[i], end = i + dp[i];
		while (start - 1 >= 0 && end + 1 < size_p && prep[start - 1] == prep[end + 1]) {
			--start;
			++end;
			++dp[i];
		}
		if (i + dp[i] > bCur) {
			bCur = i + dp[i];
			center = i;
		}
	}
	center = max_element(dp.begin(), dp.end()) - dp.begin();
	return s.substr((center - dp[center])/2, dp[center]);
}
*/

std::string longestPalindrome1(std::string s)
{
	if (s.empty())
		return "";
	std::string newS = "#";
	//O(n)
	for (char c:s)
	{
		newS += c;
		newS += "#";
	}

	const int size_newS = newS.size();

	std::vector<int> palindromeCount(size_newS,0);

	int center = 0;
	int current = 0;

	//O(n)
	for (int i = 0; i < size_newS; i++)
	{
		int mirror = center - (i-center);

		palindromeCount[i] = current <= i ? 0 : std::min(current - i, palindromeCount[mirror]);

		int start = i - palindromeCount[i], end = i + palindromeCount[i];

		while (start-1>=0 && end +1<size_newS && newS[start-1] == newS[end+1])
		{
			--start;
			++end;
			++palindromeCount[i];
		}
		if (i + palindromeCount[i] > current)
		{
			current = i + palindromeCount[i];
			center = i;
		}
	}

	center = std::max_element(palindromeCount.begin(), palindromeCount.end()) - palindromeCount.begin();
	return s.substr(center - palindromeCount[center]/2, palindromeCount[center]);
}

int main()
{
	std::cout << longestPalindrome("bbbb") << std::endl;
	std::cout << longestPalindrome("bbb") << std::endl;
	std::cout << longestPalindrome("abacddce") << std::endl;
	std::cout << longestPalindrome("babt") << std::endl;
	std::cout << longestPalindrome("bbb") << std::endl;

	return 0;
}