#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;

// 自行完成以下代码，可以任意增加函数
class BaseDataDef {
private:
	string m_type;
	string m_name;
	string m_value;
public:
	string getType() const { return m_type; }
	string getName() const { return m_name; }
	string getValue() const { return m_value; }
	void setType(const string& vType) { m_type = vType; }
	void setName(const string& vName) { m_name = vName; }
	void setValue(const string& vValue) { m_value = vValue; }

	virtual ~BaseDataDef() {}
	// 基础类型变量赋值的代码生成
	virtual string getInitializeCode() {
		string ResultStr = "";
		ResultStr += m_type + " "+ m_name;
		
		if (m_type == "string")
			ResultStr += " = \"" + m_value + "\"";
		else if (m_type == "char")
			ResultStr += " = \'" + m_value + "\'";
		else
			ResultStr += " = " + m_value;

		ResultStr += ";\n";

		return ResultStr;
	}
};

class StructDef : public BaseDataDef {
private:

public:
	void addMemeber(BaseDataDef* member) {
	}
	virtual string getInitializeCode() {
		string ResultStr = "";
		ResultStr += getType() + " " + getName();

		if (getType() == "string")
			ResultStr += " = \"" + getValue() + "\"";
		else if (getType() == "char")
			ResultStr += " = \'" + getValue() + "\'";
		else if (getType() == "int" || getType() == "float")
			ResultStr += " = " + getValue();
		else
			ResultStr += "";//结构体,待完成

		ResultStr += ";\n";

		return ResultStr;
	}
};

void split(const string& vStr, vector<string>& vioStrVec, const char vFlag = ' ')
{
	vioStrVec.clear();
	istringstream TempStrStream(vStr);
	string TempStr;
	while (getline(TempStrStream, TempStr, vFlag))
		vioStrVec.push_back(TempStr);
}

BaseDataDef* parseData(const string& vStr) {
	if (vStr.empty()) return nullptr;

	BaseDataDef* pDataDef = new BaseDataDef();
	vector<string> StrVec;
	split(vStr, StrVec, ' ');
	pDataDef->setType(StrVec[0]);
	pDataDef->setName(StrVec[1]);
	if (StrVec.size() > 2)
		pDataDef->setValue(StrVec[2]);

	return pDataDef;
}



int main() {
	int n;
	cin >> n;
	vector<string> StrVec;
	string TempStr;
	while(StrVec.size() < n)
	{
		getline(cin, TempStr);
		if (!TempStr.empty())
			StrVec.push_back(TempStr);
	}
	string res;
	for (int i = 0; i < n; ++i) {
		BaseDataDef* data = parseData(StrVec[i]);
		res += data->getInitializeCode();
		delete data;
	}
	cout << res;
	return 0;
}