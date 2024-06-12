/*************************************************
* ADS Praktikum 1.1
* RingNode.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#pragma once
#include <string>

class RingNode{
	
private:
	//
    int m_oldAge = 0;
    RingNode* m_next;
    std::string m_description = "";
    std::string m_symbolicData = "";
	//	
public:
	//
    RingNode(): m_next{nullptr} {}
    RingNode(int oldAge, std::string description, std::string symbolicData): m_oldAge{oldAge}, m_description{description}, m_symbolicData{symbolicData}, m_next{nullptr} {}
    int getOldAge() const { return this->m_oldAge; }
    void setOldAge(int oldAge) { this->m_oldAge = oldAge; }
    std::string getDescription() const { return this->m_description; }
    void setDescription(std::string description) { this->m_description = description; }
    std::string getSymbolicData() const { return this->m_symbolicData; }
    void setSymbolicData(std::string symbolicData) { this->m_symbolicData = symbolicData; }
    RingNode* getNext() const { return this->m_next; }
    void setNext(RingNode* next) { this->m_next = next; }
};

