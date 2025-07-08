#  Library for input validation
****
A lightweight C++ library for generating various random
data and timestamps.

## Features:

- **Advanced generation** — An advanced random generation method is used.
- **Modularity** — Repeated code fragments have been extracted into individual functions .

## Limitations:

⚠️ **Current limitations:**

1. **Thread safety**: Not thread-safe (uses std::random_device)
2. **String characters**: Only generates lowercase ASCII (a-z))
3. **Timestamp format**: Fixed format (YYYY-MM-DD HH:MM:SS)

## List of Functions:
In order not to clutter it up, I moved it [here](./ListOfFunctions_megagenerate.md).

## Usage example:

**Input:**
```C++
#include "generate.h"
#include <iostream>

int main() {
    using namespace generate;
    
    // Generate different types of random data
    std::string index = generateStringIndex();
    int randomInt = generateRandomIntNumber(1, 100);
    double randomDouble = generateRandomDoubleNumber(0.0, 1.0);
    std::string randomStr = generateRandomString(10);
    std::string timestamp = generateCurrentDataTime();

    // Display results
    std::cout << "=== Generation Results ===\n"
              << "String Index: " << index << "\n"
              << "Random Integer: " << randomInt << "\n"
              << "Random Double: " << randomDouble << "\n"
              << "Random String: " << randomStr << "\n"
              << "Current Timestamp: " << timestamp << std::endl;

    return 0;
}
```

**Output:**
```C++
=== Generation Results ===
String Index: 004271
Random Integer: 42
Random Double: 0.731234
Random String: qgtrx
Current Timestamp: 2023-11-15 14:30:45
```

## Lessons Learned

🔧 **Development insights:**

- **Code Structure**: Mastered header/source separation
- **Random generation**: Mastered advanced type of generation
- **Methods of String generation**: Discovered new string generation methods










