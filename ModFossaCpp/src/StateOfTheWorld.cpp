#include "StateOfTheWorld.h"

#include <iostream>

StateOfTheWorld::StateOfTheWorld() :
voltage(-999),
concentrations() {
}

StateOfTheWorld::~StateOfTheWorld() {
    //if (concentrations != NULL) {
      //  delete concentrations;
    //}
}

double StateOfTheWorld::getVoltage() const {
    return voltage;
}

double StateOfTheWorld::getConcentration(string ligand_name) const {
    if (concentrations == NULL) {
        throw std::runtime_error("map of Concentrations not set");
    }

    map<string, Concentration*>::const_iterator it;
    it = concentrations->find(ligand_name);
    if (it == concentrations->end()) {
        throw std::runtime_error(
                "Error in getConcentration: ligand does not exist");
    }

    return (it->second->concentration_value);
}

void StateOfTheWorld::addConcentration(string ligand_name, 
        double concentration_value) {
    if (concentrations == NULL) {
        concentrations = new map<string, Concentration*>();
    }

    (*concentrations)[ligand_name] = new Concentration(ligand_name, 
            concentration_value);
}

void StateOfTheWorld::setVoltage(double voltage) {
    this->voltage = voltage;
}

//void StateOfTheWorld::setConcentrations(map<string, Concentration*>&
//        concentrations) {
//    if (this->concentrations != NULL) {
//        delete this->concentrations;
//    }
//
//    this->concentrations = &concentrations;
//}