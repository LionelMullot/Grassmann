#include "GCA_scalar.hpp"
#include "GCA_antiquadvector.hpp"
#include <iostream>

gca::GCA_scalar::GCA_scalar():
	value(1){}

gca::GCA_scalar::GCA_scalar(const gca::GCA_scalar& other):
	value(other.value){}

gca::GCA_scalar::GCA_scalar(const double value):
	value(value){}

double& gca::GCA_scalar::getValue(){
    return value;
}

gca::GCA_scalar& gca::GCA_scalar::operator=(const gca::GCA_scalar& Other){
    this->value = Other.value;
}

gca::GCA_scalar& gca::GCA_scalar::operator^(const gca::GCA_scalar& Other){
    this->value *= Other.value;
}

gca::GCA_vector gca::GCA_scalar::operator^(gca::GCA_vector vector){ // Je passe une copie pour ne pas modifier le vecteur d'origine
	for(unsigned int i = 0; i < vector.size(); ++i){
    	vector[i] *= this->value;
    }
    return vector;
}

gca::GCA_scalar& gca::GCA_scalar::operator<<(const double& in){
    this->value = in;
}

gca::GCA_antiquadvector gca::GCA_scalar::operator~(){
    gca::GCA_antiquadvector result;
    result << this[0].value;
    return result;
}

std::ostream& gca::operator<<(std::ostream& os, gca::GCA_scalar& scalar){
  os << scalar.getValue();
  return os;
}
