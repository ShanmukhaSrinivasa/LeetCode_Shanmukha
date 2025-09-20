class Spreadsheet {
public:
    unordered_map<string,int> sheet;
    Spreadsheet(int rows) {}

    void setCell(string cell, int value) {
        sheet[cell] = value;
    }

    void resetCell(string cell) { 
        sheet[cell] = 0;
     }

    int getCellValue(string cell){
        return sheet[cell];
    }

    int getValue(string formula) {
        
        string X = "";
        string Y = "";
        bool flag = true;

        for (int i = 1; i < formula.size(); i++) {
            char c = formula[i];
            if (c == '+') {
                flag = false;
                continue;
            }

            if (flag) {
                X += c;
            } else {
                Y += c;
            }
        }

        int xVal = 0;
        int yVal = 0;

        if (isdigit(X[0])) {
            xVal = stoi(X);
        } else {
            xVal = getCellValue(X);
        }
        if (isdigit(Y[0])) {
            yVal = stoi(Y);
        } else {
            yVal = getCellValue(Y);
        }

        return xVal + yVal;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */