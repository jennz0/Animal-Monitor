## Animal Simulator Documentation

### Overview

The Animal Simulator provides a visualization of an idealized food-chain model. There are ponds and herbivore animals on the prairie, as well as the carnivore animals who fed on them.

Each data point within the map represents an animal according to its color. Each animal has its own gender, species, and status. The species attribute contains the name of the species and the ideal temperature for the animal to breed. The status attribute contains the hunger and thirst level of the animal, including the ideal, current, maximum, minimum hunger and thirst level. The status also contains an attribute called _alive_, which indicates whether the current animal is alive or not. An animal can die if: 1. The hunger or thirst level is below the minimum requirement for it to live. 2. The animal is hunted by its predators.

Initially the animals are randomly moving around the map. At some point, they may get hungry or thirsty, which will drive them to hunt or approach the nearest pond to drink. When the temperature is ideal for the animals to breed, they will search for another animal within its species to mate.

### Directory Structure

To run the visualization app, simply build with the CMakeLists.txt, which contains the dependencies of the program. Then run the CINDER_APP() in main.cpp.

```
project
│   README.md
|   CMakeLists.txt
|
└───app
|   |   main.cpp
│
└───assets
│   |   lion.png
|   |   zebra.png
│   |   bison.png
|
|
└───include
│   |   animal.h
|   |   motion.h
│   |   status.h
|   |   species.h
|   |   sim.h
|   |   sim_app.h
|
└───src
   |   animal.cpp
   |   motion.cpp
   |   status.cpp
   |   species.cpp
   |   sim.cpp
   |   sim_app.cpp
```

