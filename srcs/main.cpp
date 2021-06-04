#include "VectorTester.hpp"
#include "StackTester.hpp"
#include "QueueTester.hpp"
#include "ListTester.hpp"
#include "MapTester.hpp"

int     main()
{
    vector_tester::main();
    stack_tester::main();
    queue_tester::main();
    list_tester::main();
    map_tester::main();

    return (0);
}