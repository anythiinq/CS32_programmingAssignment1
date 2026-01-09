// NOT DONE YET I THINK
#ifndef HISTORY_H
#define HISTORY_H

class History
	{
	  public:
	    History(int nRows, int nCols);
	    bool record(int r, int c);
	    void display() const;
	};

#endif
