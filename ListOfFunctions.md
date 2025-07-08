## List of functions:
| Function | Description | Example |
|----------|-------------|---------|
| **`generateStringIndex()`** | Generates 6-digit zero-padded string (000001-999999) | `std::string id = generate::generateStringIndex();` |
| **`generateRandomIntNumber(min, max)`** | Returns random integer in [min,max] range | `int age = generate::generateRandomIntNumber(18, 99);` |
| **`generateRandomDoubleNumber(min, max)`** | Returns random double in [min,max] range | `double temp = generate::generateRandomDoubleNumber(-10.5, 42.0);` |
| **`generateCurrentDataTime()`** | Returns current datetime as "YYYY-MM-DD HH:MM:SS" | `std::string now = generate::generateCurrentDataTime();` |
| **`generateRandomString(max_length)`** | Generates random lowercase string (1-max_length chars) | `std::string code = generate::generateRandomString(12);` |
[Return back](./README.md)
