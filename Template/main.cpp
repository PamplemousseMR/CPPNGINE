#include "template.hpp"
#include "template.hxx"

#include <assert.h>

/*
    this project test template specialization
*/
int main()
{
    TemplateMethod tempMethod;
    assert(STANDARD == tempMethod.getTemplate< void >());
    assert(SPECIALIZED == tempMethod.getTemplate< int >());

    MultiTemplateMethod multiTempMethod;
    assert(STANDARD == (multiTempMethod.getTemplate< void, void >()) );
    assert(SPECIALIZED == (multiTempMethod.getTemplate< int, int >()) );

    TemplateClass< void > tempClass;
    assert(STANDARD == tempClass.getTemplate());

    TemplateClass< int > tempClassSpe;
    assert(SPECIALIZED == tempClassSpe.getTemplate());

    TemplateClass< std::vector< void > > tempClassChange;
    assert(CHANGE == tempClassChange.getTemplate());

    TemplateClass< std::vector< int > > tempClassChangeSpe;
    assert(CHANGESPE == tempClassChangeSpe.getTemplate());

    MultiTemplateClass< void, void > multiTempClass;
    assert(STANDARD == multiTempClass.getTemplate());

    MultiTemplateClass< int, int > multiTempClassSpe;
    assert(SPECIALIZED == multiTempClassSpe.getTemplate());

    MultiTemplateClass< void, int > multiTempClassPars;
    assert(PARCIAL == multiTempClassPars.getTemplate());

    MultiTemplateClass< void, std::vector< void > > multiTempClassChange;
    assert(CHANGE == multiTempClassChange.getTemplate());

	return 0;
}
