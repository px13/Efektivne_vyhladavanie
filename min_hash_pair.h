#include <seqan/sequence.h>
#include <deque>
#include <map>

using namespace std;

typedef seqan::Infix<seqan::DnaString>::Type  DnaInfix;

class MinHashPair
{
public:

	const int N = 32;
	const int M = 13;
	const int N_MINUS_M = N - M;

	bool preprocessDone;

	MinHashPair(seqan::DnaString &sequence, const int n = 32, const int m = 13);
	void prepare();
	void query(vector<seqan::DnaString> &queries, vector<deque<int>> &out);

	void setText(seqan::DnaString &sequence);

private:
	seqan::DnaString sequence;
	multimap<int, int> map;
	vector<pair<int, int>> pole;

	void addMinSegmentToMap(DnaInfix &segment1, DnaInfix &segment2);
	void findMinSegmentOfLengthM(DnaInfix &segment1, DnaInfix &segment2);
	void minSegment(const DnaInfix &segment1, DnaInfix &segment2);
	void addSegmentToMap(const DnaInfix &segment);
	void spracuj();

	void findQueries(vector<seqan::DnaString> &queries, vector<deque<int>> &out);
	void findQuery(seqan::DnaString &query, deque<int> &out);
	int isCorrect(seqan::DnaString &query, const int &beginSegment, const DnaInfix &queryMinSegment);

	int segmentToNumber(const DnaInfix &segment);
};