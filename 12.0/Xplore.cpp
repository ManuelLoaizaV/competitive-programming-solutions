#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll numberOfAuthors = 0;
map<string, ll> ind;
std::map<string, ll>::iterator it;
vector <Author> authorAnswer;

struct Author {
	string name;
	ll answer;
	vector<ll> citations;
    bool operator < (Author &b) const {
        if (answer == b.answer) return name < b.name;
        return answer > b.answer;
    }
};

ll stringToInt(string s) {
    ll answer = 0;
    int l = s.size();
    for (int i = 0; i < l; i++) {
        answer = 10 * answer + (s[i] - '0');
    }
    return answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string line;
	getline(cin, line);
	while (n--) {
		getline(cin, line);
		bool readingAuthors = true;
		vector<string> authors;
		int comillas1 = 0;
		int comillas2 = 0;
		// {"authors": {"authors": [{"author_order": 1,"affiliation": "","full_name": "Echo"}, {"author_order": 2,"affiliation": "","full_name": "Bravo"}, {"author_order": 3,"affiliation": "","full_name": "Alfa"}]},"title": "Article Title 1","article_number": "1","publication_title": "Publication Title 1","publication_number": "7","citing_paper_count": 9,"publisher": "IEEE"}
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == '"') {
				comillas1 = comillas2;
				comillas2 = i;
			}
			if (line[i] == '}' and readingAuthors) {
				string author_name;
				author_name = line.substr(comillas1 + 1, comillas2 - comillas1 - 1);
				authors.push_back(author_name);		
			}
			if (line[i] == ']') readingAuthors = false;
			if (not readingAuthors and '0' <= line[i] and line[i] <= '9' 
				and line.substr(comillas1 + 1, comillas2 - comillas1 - 1) == "citing_paper_count") {
				string citing_paper_count;
				for (int j = i + 1; j < line.size(); j++) {
					if (line[j] == ',') {
						citing_paper_count = line.substr(i, j - i);
						break;
					}
				}
				int l = authors.size();
		        ll count = stringToInt(citing_paper_count);
		        for (int k = 0; k < l; k++) {
			        it = ind.find(authors[k]);
			        if (it == ind.end()) {
				        ind[authors[k]] = numberOfAuthors;
				        Author xd;
				        xd.name = authors[k];
				        authorAnswer.push_back(xd);
				        numberOfAuthors++;
			        }
			        authorAnswer[ind[authors[k]]].citations.push_back(count);
		        }
				break;
			}
		}
	}
	for (int i = 0; i < numberOfAuthors; i++) {
		sort(authorAnswer[i].citations.begin(), authorAnswer[i].citations.end());
		ll length = authorAnswer[i].citations.size();
		ll h = 0;
		for (int j = authorAnswer[i].citations.size() - 1; j >= 0; j--) {
			ll temp = min(length - j, authorAnswer[i].citations[j]);
			h = max(h, temp);
		}
		authorAnswer[i].answer = h;
	}
	sort(authorAnswer.begin(), authorAnswer.end());
	for (int i = 0; i < numberOfAuthors; i++) {
		cout << authorAnswer[i].name << " " << authorAnswer[i].answer << endl;
	}	
	return 0;
}