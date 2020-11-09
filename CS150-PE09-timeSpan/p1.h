#ifndef P1_H
#define P1_H
// Define your class here
class TimeSpan
{
private:
	double h_, m_;
public:
	TimeSpan();
	TimeSpan(double, double);
	double hours() const;
	double minutes() const;
	double hourspan() const;
	std::string toString() const;
	bool operator<(const TimeSpan&) const;
	friend ostream& operator<<(ostream& os, TimeSpan t);
};




#endif