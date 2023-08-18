#include <iostream>
#include <vector>

using namespace std;

struct DnaParts {
	int a;
	int c;
	int g;
	int t;
	DnaParts(){} 
	DnaParts(const string str)
	{
		a = (int)count(str.begin(), str.end(), 'A');
		c = (int)count(str.begin(), str.end(), 'C');
		g = (int)count(str.begin(), str.end(), 'G');
		t = (int)count(str.begin(), str.end(), 'T');
	}
	bool operator<=(const DnaParts& d) 
	{ 
		return a <= d.a && c <= d.c && g <= d.g && t <= d.t; 
	}
	bool IsEqual(const DnaParts& d) const { return a == d.a && c == d.c && g == d.g && t == d.t; }
	friend ostream& operator<<(ostream&, DnaParts&);
	friend istream& operator>>(istream&, DnaParts&);
};
// find 함수에 DnaParts 구조체를 넣기 위한 몸부림. 
// bool operator==(const DnaParts& d1, const DnaParts& d2) { return d1.IsEqual(d2); }
ostream& operator<<(ostream& ostrm, DnaParts& d)
{
	cout << d.a << ' ' << d.c << ' ' << d.g << ' ' << d.t;
	return ostrm;
}
istream& operator>>(istream& istrm, DnaParts& d)
{
	istrm >> d.a >> d.c >> d.g >> d.t;
	return istrm;
}

int s, p;
DnaParts goal;
string dna_string;
vector<string> rna_parts;

int SlidingWindow()
{
	int start = 0, end = p, cnt = 0;
	DnaParts* rna = new DnaParts(dna_string.substr(start, p));
	while (end <= s)
	{
		if (goal <= *rna)
		{
			//string rna_string = dna_string.substr(start, p);
			//if(rna_parts.end() == find(rna_parts.begin(), rna_parts.end(), rna_string))
			//{
			//	rna_parts.push_back(rna_string);
				cnt++;
			//}
		}
		if (dna_string[start] == 'A') rna->a--;
		else if (dna_string[start] == 'C') rna->c--;
		else if (dna_string[start] == 'G') rna->g--;
		else if (dna_string[start] == 'T') rna->t--;
		if (dna_string[end] == 'A') rna->a++;
		else if (dna_string[end] == 'C') rna->c++;
		else if (dna_string[end] == 'G') rna->g++;
		else if (dna_string[end] == 'T') rna->t++;
		start++;
		end++;
	}
	return cnt;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> s >> p >> dna_string >> goal;

	cout << SlidingWindow();

	return 0;
}