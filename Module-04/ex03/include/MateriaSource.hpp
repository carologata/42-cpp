#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#define SOURCE_SIZE 4

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

typedef struct s_node {

    AMateria    *memAddress;
    struct      s_node *next;

} t_node;

class MateriaSource : public IMateriaSource {

public:

    MateriaSource(void);
    MateriaSource(const MateriaSource& copy);
    MateriaSource& operator=(const MateriaSource& copy);
    ~MateriaSource(void);

    void        learnMateria(AMateria *materia);
    AMateria    *createMateria(std::string const & type);

    t_node      *createNode(AMateria *address);
    void        addListBack(AMateria *address);

private:

    AMateria    *_source[SOURCE_SIZE];
    t_node      *materiaList;

};

#endif