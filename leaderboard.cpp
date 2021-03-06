// leaderboard.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>

using namespace std;

//int input_arr[100] = {295,294,291,287,287,285,285,284,283,279,277,274,274,271,270,268,268,268,264,260,259,258,257,255,252,250,244,241,240,237,236,236,231,227,227,227,226,225,224,223,216,212,200,197,196,194,193,189,188,187,183,182,178,177,173,171,169,165,143,140,137,135,133,130,130,130,128,127,122,120,116,114,113,109,106,103,99,92,85,81,69,68,63,63,63,61,57,51,47,46,38,30,28,25,22,15,14,12,6,4};
//int alice_in_arr[200] = { 5,5,6,14,19,20,23,25,29,29,30,30,32,37,38,38,38,41,41,44,45,45,47,59,59,62,63,65,67,69,70,72,72,76,79,82,83,90,91,92,93,98,98,100,100,102,103,105,106,107,109,112,115,118,118,121,122,122,123,125,125,125,127,128,131,131,133,134,139,140,141,143,144,144,144,144,147,150,152,155,156,160,164,164,165,165,166,168,169,170,171,172,173,174,174,180,184,187,187,188,194,197,197,197,198,201,202,202,207,208,211,212,212,214,217,219,219,220,220,223,225,227,228,229,229,233,235,235,236,242,242,245,246,252,253,253,257,257,260,261,266,266,268,269,271,271,275,276,281,282,283,284,285,287,289,289,295,296,298,300,300,301,304,306,308,309,310,316,318,318,324,326,329,329,329,330,330,332,337,337,341,341,349,351,351,354,356,357,366,369,377,379,380,382,391,391,394,396,396,400};
int input_arr[7] = { 100, 100, 50, 40, 40, 20, 10 };
int alice_in_arr[4] = { 5, 25, 50, 120 };

vector<int> climbingLeaderboard(std::vector<int> scores, vector<int> alice) {
	int done = 0, temp_rank = 0, enter_flag = 0;
	unsigned end = scores.size();
	unsigned update_size = 0;
	vector<int> alice_rank;

	update_size = scores.size();

	std::sort(scores.begin(), scores.end(), std::greater<int>());

	for (unsigned i = 0; i < (update_size - 1); i++) {
		if ((scores.at(i) == scores.at(i + 1))) {
			scores.erase(scores.begin() + i);
			i--;
		}
		update_size = scores.size();
	}
	end = update_size;

	for (unsigned j = 0; j < alice.size(); j++) {
		done = 0;
		do {
			if (j > 0) {
				if (alice.at(j) == alice.at(j - 1)) {
					alice_rank.push_back(temp_rank);
					enter_flag = 1;
					done = 1;
				}
				else {
					enter_flag = 0;
				}
			}
			if (enter_flag == 0) {
				if (alice.at(j) == scores.at(end - 1)) {
					alice_rank.push_back(end);
					temp_rank = end;
					done = 1;
				}
				else if (alice.at(j) < scores.at(end - 1)) {
					alice_rank.push_back(end + 1);
					temp_rank = end + 1;
					done = 1;
				}
				else {
					if (end == 1) {
						alice_rank.push_back(end);
						temp_rank = end;
						done = 1;
					}
					else {
						end--;
					}
				}
			}
			
		} while (done != 1);
	}

	return alice_rank;
}


void print_array(std::vector<int> scores, vector<int> alice_rank) {
	for (unsigned i = 0; i < scores.size(); i++) {
		cout << scores.at(i) << " ,";
	}
	cout << "\n";
	cout << "\n";
	for (unsigned j = 0; j < alice_rank.size(); j++) {
		cout << alice_rank.at(j) << " ,";
	}
	cout << "\n";
}

int main()
{
	vector<int> score_arr;
	vector<int> alice_score;
	vector<int> alice_final;

	for (int i = 0; i < 7; i++) {
		score_arr.push_back(input_arr[i]);
	}
	for (int i = 0; i < 4; i++) {
		alice_score.push_back(alice_in_arr[i]);
	}
	alice_final = climbingLeaderboard(score_arr, alice_score);
	print_array(score_arr, alice_final);
	return 0;
}
