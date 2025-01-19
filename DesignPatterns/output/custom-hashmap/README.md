# Custom HashMap

This project implements a custom HashMap in C++ with two collision resolution strategies: Separate Chaining and Open Addressing.

## Project Structure

```
custom-hashmap
├── src
│   ├── HashMap.cpp          # Implementation of the HashMap class
│   ├── HashMap.h            # Declaration of the HashMap class
│   ├── main.cpp             # Entry point of the application
│   └── strategies
│       ├── CollissionResolutionStrategy.h  # Abstract base class for collision resolution strategies
│       ├── SeparateChaining.h              # Implementation of Separate Chaining strategy
│       └── OpenAddressing.h                # Implementation of Open Addressing strategy
├── CMakeLists.txt          # CMake configuration file
└── README.md               # Project documentation
```

## Features

- **Separate Chaining**: Handles collisions by maintaining a list of entries for each bucket.
- **Open Addressing**: Resolves collisions by finding the next available slot in the array.

## Building the Project

To build the project, follow these steps:

1. Ensure you have CMake installed on your system.
2. Navigate to the project directory.
3. Create a build directory:
   ```
   mkdir build
   cd build
   ```
4. Run CMake to configure the project:
   ```
   cmake ..
   ```
5. Build the project:
   ```
   make
   ```

## Usage

After building the project, you can run the application using the following command:

```
./your_executable_name
```

Replace `your_executable_name` with the name of the generated executable.

## Contributing

Feel free to contribute to this project by submitting issues or pull requests.