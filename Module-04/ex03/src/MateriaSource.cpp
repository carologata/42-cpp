#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _source(), materiaList(NULL) {

    std::cout << "MateriaSource: Default Constructor called." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& copy) : _source(), materiaList(NULL) {

    std::cout << "MateriaSource: Copy Constructor called." << std::endl;
    *this = copy;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy) {

    std::cout << "MateriaSource: Assignment Operator called." << std::endl;

    if(this != &copy) {
        for(int i = 0; i < SOURCE_SIZE; i++) {
            if(_source[i]) {
                delete _source[i];
                _source[i] = NULL;
            }
            if(copy._source[i])
                _source[i] = copy._source[i]->clone(); 
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource(void) {

    std::cout << "MateriaSource: Destructor called." << std::endl;

    for(int i = 0; i < SOURCE_SIZE; i++) {
        if(_source[i]) {
            delete _source[i];
            _source[i] = NULL;
        }
    }
    while (materiaList) {
        t_node *tmp = materiaList; 
        materiaList = materiaList->next;
        if(tmp->memAddress) {
            delete tmp->memAddress; 
            tmp->memAddress = NULL;
        }
        delete tmp; 
    }
}

void MateriaSource::learnMateria(AMateria *materia) {

    for(int i = 0; i < SOURCE_SIZE; i++) {
        if(_source[i] == NULL && materia != NULL) {
            addListBack(materia);
            _source[i] = materia->clone(); //Copies the Materia passed as a parameter
            std::cout << "Materia " << materia->getType() << " learned." << std::endl;
            return ;
        }
    }
    if(materia != NULL) 
        addListBack(materia);
    std::cout << "Materia " << materia->getType() << " was not learned." << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const & type) {

    for(int i = 0; i < SOURCE_SIZE; i++) {
        if(_source[i] && _source[i]->getType() == type) {
            AMateria *address = _source[i]->clone();
            std::cout << "Materia " << type << " created." << std::endl;
            addListBack(address);
            return (address); 
        }
    }
    std::cout << "Materia " << type << " was not created." << std::endl;
    return (NULL);
}

t_node *MateriaSource::createNode(AMateria *address) {

    t_node *node = new t_node();
    node->memAddress = address;
    node->next = NULL;
    return (node);
}

void MateriaSource::addListBack(AMateria *address) {

    if(address == NULL)
        return ;
    t_node *node = createNode(address);
    if(materiaList == NULL)
        materiaList = node;
    else {
        t_node *tmp = materiaList;
        while(tmp->next)
            tmp = tmp->next;
        tmp->next = node;
    }   
}