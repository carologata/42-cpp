#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource(void) : materiaList(NULL) {

    std::cout << "MateriaSource: Default Constructor called." << std::endl;

    for(int i = 0; i < SOURCE_SIZE; i++)
        _source[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy) : materiaList(NULL) {

    std::cout << "MateriaSource: Copy Constructor called." << std::endl;

    for(int i = 0; i < SOURCE_SIZE; i++)
        _source[i] = NULL;
    *this = copy;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy) {

    std::cout << "MateriaSource: Assignment Operator called." << std::endl;

    if(this != &copy) {
        for(int i = 0; i < SOURCE_SIZE; i++) {
            if(_source[i])
                delete _source[i];
            if(copy._source[i])
                _source[i] = copy._source[i]->clone(); 
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource(void) {

    std::cout << "MateriaSource: Destructor called." << std::endl;

    for(int i = 0; i < SOURCE_SIZE; i++) {
        if(_source[i])
            delete _source[i];
    }
    while (materiaList) {
        t_node *tmp = materiaList; 
        materiaList = materiaList->next; 
        delete tmp->memAddress; 
        delete tmp; 
    }
}

void MateriaSource::learnMateria(AMateria *materia) {

    for(int i = 0; i < SOURCE_SIZE; i++) {
        if(_source[i] == NULL && materia != NULL) {
            _source[i] = materia->clone(); //Copies the Materia passed as a parameter
            std::cout << "Materia " << materia->getType() << " learned." << std::endl;
            break ;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const & type) {

    for(int i = 0; i < SOURCE_SIZE; i++) {
        if(_source[i] && _source[i]->getType() == type) {
            std::cout << "Materia " << type << " created." << std::endl;
            AMateria *address = _source[i]->clone();
            addListBack(address);
            return (address); 
        }
    }
    return (0);
}

t_node *MateriaSource::createNode(AMateria *address) {

    t_node *node = new t_node();
    node->memAddress = address;
    node->next      = NULL;
    return (node);
}

void MateriaSource::addListBack(AMateria *address) {

    if(address == NULL)
        return ;
    
    t_node *node = createNode(address);
    if(materiaList == NULL)
        materiaList = node;
    else {
        while(materiaList)
            materiaList = materiaList->next;
        materiaList = node;
    }   
}