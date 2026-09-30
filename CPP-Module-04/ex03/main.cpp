/*
Materia (Skills): Ice or Cure
Character (Hero): Has a Backpack with 4 slots for skills
                  equip: Put a skill book into an empty slot (0–3)
                  unequip: Drop the book on the floor. (Do NOT burn/delete it yet!)
                  use: Cast the skill from a slot onto a target
MateriaSource (Skill Shop): 4 skill templates
                  learnMateria: Store a master copy of a skill
                  createMateria: Print a new copy (clone) of a stored skill for the hero to use
Deep Copy:        When you copy a Hero, you must copy every book in their backpack
                  Two heroes should never share the same physical book; they each need their own "photocopy"

SHALLOW COPY： copies the memory addresses of pointers
               both objects share the same underlying data
DEEP    COPY:  allocates new memory & duplicates the actual data
               two objects are completely independent and don't interfere with each other

(A)ABSTRACT : has member variables, implemented functions, pure virtual fucntions(cannot be instantiated)
(I)INTERFACE: without member variables, only has pre virtual method(cannot be instantiated)
*/

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main(void)
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);

    delete bob;
    delete me;
    delete src;

//     // //test----------------------------------
//     // ICharacter* Alice = new Character("Alice");
//     // Alice->equip(new Ice());
//     // Alice->equip(new Ice());
//     // Alice->equip(new Cure());
//     // Alice->equip(new Cure());

//     // ICharacter* copyAlice = new Character(*(Character*)Alice); //test deep copy

//     // Character   Molly("Molly"); //test operator=
//     // Molly = *(Character*)Alice;

//     // Alice->use(0, Molly);
//     // Alice->use(1, Molly);
//     // Alice->use(2, Molly);
//     // Alice->use(3, Molly);

//     // Alice->unequip(0);
//     // Alice->unequip(1);
//     // Alice->unequip(2);
//     // Alice->unequip(3);

//     // std::cout << "copyAlice should still have Ice: " << std::endl;
//     // copyAlice->use(0, *Alice);
//     // copyAlice->use(1, *Alice);
//     // copyAlice->use(2, *Alice);
//     // copyAlice->use(3, *Alice);
//     // std::cout << "Molly should still have Ice: " << std::endl;
//     // Molly.use(0, *Alice);
//     // Molly.use(1, *Alice);
//     // Molly.use(2, *Alice);
//     // Molly.use(3, *Alice);

//     // delete Alice;
//     // delete copyAlice;

    return 0;
}


// int main()
// {
//     std::cout << "=== TEST MateriaSource ===" << std::endl;
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());

//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     AMateria* tmp2 = src->createMateria("cure");
//     AMateria* tmpFail = src->createMateria("fire"); // nullptr

//     std::cout << "tmpFail should be nullptr: " << tmpFail << std::endl;

//     std::cout << "\n=== TEST Character equip/use ===" << std::endl;
//     ICharacter* alice = new Character("Alice");
//     alice->equip(tmp);
//     alice->equip(tmp);
//     alice->equip(tmp2);
//     alice->equip(tmp2);

//     ICharacter* bob = new Character("Bob");

//     for (int i = 0; i < 4; i++)
//         alice->use(i, *bob);

//     std::cout << "\n=== TEST deep copy (copy constructor) ===" << std::endl;
//     ICharacter* copyAlice = new Character(*(Character*)alice);
//     std::cout << "copyAlice uses its skills on Bob:" << std::endl;
//     for (int i = 0; i < 4; i++)
//         copyAlice->use(i, *bob);

//     std::cout << "\n=== TEST operator= ===" << std::endl;
//     Character molly("Molly");
//     molly = *(Character*)alice;
//     std::cout << "Molly uses her skills on Bob:" << std::endl;
//     for (int i = 0; i < 4; i++)
//         molly.use(i, *bob);

//     std::cout << "\n=== TEST unequip / floor management ===" << std::endl;
//     alice->unequip(0);
//     alice->unequip(1);
//     alice->unequip(2);
//     alice->unequip(3);

//     std::cout << "After Alice unequip, copyAlice and Molly still have their skills:" << std::endl;
//     for (int i = 0; i < 4; i++)
//     {
//         copyAlice->use(i, *bob);
//         molly.use(i, *bob);
//     }

//     delete alice;
//     delete copyAlice;
//     delete bob;
//     delete src;

//     std::cout << "\n=== END TEST ===" << std::endl;
//     return 0;
// }

// int main()
// {
//     std::cout << "--- 1. Testing MateriaSource Template Limit (Max 4) ---" << std::endl;
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());   
//     src->learnMateria(new Cure());   
//     src->learnMateria(new Ice());    
//     src->learnMateria(new Cure());   
    
//     AMateria* extraMateria = new Ice();
//     src->learnMateria(extraMateria); 

//     std::cout << "\n--- 2. Testing Character Inventory Limit (Max 4) ---" << std::endl;
//     Character* alice = new Character("Alice");
//     for (int i = 0; i < 6; i++)
//     {
//         AMateria* m = src->createMateria(i % 2 == 0 ? "ice" : "cure");
//         std::cout << "Equipping item " << i << "... ";
//         alice->equip(m);
//     }

//     std::cout << "\n--- 3. Testing Floor Overflow (unequip management) ---" << std::endl;

//     for (int i = 0; i < 10; i++)
//     {
//         alice->equip(src->createMateria("ice"));
//         alice->unequip(0); 
//     }
//     std::cout << "Check Valgrind for 10 items on the floor..." << std::endl;

//     std::cout << "\n--- 4. Testing Deep Copy with Floor ---" << std::endl;
//     Character* bob = new Character("Bob");
//     bob->equip(src->createMateria("ice"));
//     bob->unequip(0);

//     Character* bobCopy = new Character(*bob);
    
//     std::cout << "\n--- 5. Final Cleanup ---" << std::endl;
//     delete alice;
//     delete bob;
//     delete bobCopy;
//     delete src;

//     std::cout << "Test finished. Run with Valgrind!" << std::endl;
//     return 0;
// }