# box2cpp
C++ Abstraction layer over Box2D


### ToDo:

- Add multi-threading
- Abstract math vectors
- Abstract enums
- Add:
	- World
	- Body
	- Shape
	- Chain
	- all joint kinds, DynamicTree, Recording, RecPlayer.



### Memory management

- Each type is responsible for destroying what it added.
Eg: World destroys added bodies