/*************************************************
* ADS Praktikum 1.1
* Ring.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .cpp
#include "Ring.h"
#include <iostream>

// Ihr Code hier:
void Ring::addNewNode(std::string description, std::string symbolicData) {
    RingNode* neuer_eintrag = new RingNode(0, description, symbolicData);
    if (m_anker == nullptr) {                            // leere Liste
        m_anker = neuer_eintrag;
        m_anker->setNext(neuer_eintrag);
        m_countNodes++;
    }
    else {                                               // Knoten altern
        RingNode* ptr = m_anker;
        for (int i = 0; i < m_countNodes; i++) {
            ptr->setOldAge(ptr->getOldAge() + 1);
            ptr = ptr->getNext();
        };
        if (m_anker->getNext()->getOldAge() == 6) {      // volle Liste
            RingNode* todelete = m_anker->getNext();
            neuer_eintrag->setNext(todelete->getNext());
            delete todelete;
        }
        else {                                           // nicht-volle Liste
            neuer_eintrag->setNext(m_anker->getNext());
            m_countNodes++;
        }
        m_anker->setNext(neuer_eintrag);
        m_anker = neuer_eintrag;
    }
}

bool Ring::search(std::string symbolicData) {
    RingNode* ptr = m_anker;
    bool gefunden = false;
    for (int i = 0; i < m_countNodes; i++) {
        if (ptr->getSymbolicData() == symbolicData) {
            std::cout << "++ Gefunden in Backup: Alter: " << ptr->getOldAge() << ", Beschreibung: " << ptr->getDescription() << ", Daten: " << ptr->getSymbolicData() << std::endl;
            gefunden = true;
        }
        ptr = ptr->getNext();
    }
    if (!(gefunden))
        std::cout << "++ Datensatz konnte nicht gefunden werden.\n";
    return gefunden;
}

void Ring::print() {
    /* if (m_anker->getNext() == nullptr) {
        std::cout << "Es sind keine Datensaetze vorhanden!!\n";
        return;
    } */
    RingNode* ptr = m_anker->getNext();
    std::string agecounter[6];
    int x = m_countNodes;
    /*
    if (ptr == nullptr) {
        std::cout << "Es sind keine Datensaetze vorhanden!!\n";
    } */
    while (x > 0) {
        agecounter[x - 1] = "Alter: " + std::to_string(ptr->getOldAge()) + ", Beschreibung: " + ptr->getDescription() + ", Daten: " + ptr->getSymbolicData() + "\n";
        ptr = ptr->getNext();
        x--;
    }
    for (int i = 0; i < m_countNodes; i++) {
        if (i < m_countNodes - 1) {
            std::cout << agecounter[i] + "--------------------------" + "\n";
        }
        else {
            std::cout << agecounter[i];
        }
    }
}
//
////////////////////////////////////