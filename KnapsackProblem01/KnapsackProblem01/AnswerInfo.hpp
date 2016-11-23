#ifndef ANSWER_INFO_H
#define ANSWER_INFO_H

#include <string>

class AnswerInfo {
public:
	std::string MethodName;
	double CalTime;
	AnswerInfo(std::string MethodName, double CalTime) {
		this->MethodName = MethodName;
		this->CalTime = CalTime;
	}
};

#endif /* ANSWER_INFO_H */