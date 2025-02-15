# Assignment_04

**Frame Rate, Sprites, and Textures**

In this assignment we will be implementing frame capping, frame independent movement, and a refactoring of our rectangle class into a Sprite class.

**Requirements**

Copy over your files from the previous assignment into the Assignment directory of this assignment. Please note there is an included Assets directory that you'll be using to create textures.<br><br> 
***NOT REQUIRED:*** If you want to create your own .bmp files for your assignment, you may but you need to make sure they are 40px by 40px and have the proper RGBA scheme.

**1. Frame Rate**

***1a. Modify Application Loop().*** Modify the function to accept a target frame rate as a parameter.<br>

***1b. Implement Frame Capping.*** This involves calculating how long a single frame takes (input/update/render), finding out our "budget" for rendering a single frame, and seeing if our elapsed time is less than our budgeted time, and if so, implementing a delay. This should all be done in your application loop.<br><br>
Key Functions for this section are:
* SDL_GetTicks()
* SDL_Delay()<br>

***1c. Track Frame rate.*** Though we have a target frame rate, we need to track our actual frame rate to make sure our program works properly and so the user can see their current frame rate. This involves tracking how many frames (input/update/render) execute in 1 second. Then, we can update our Window Title to include this frame rate. This should all be done in your application loop. <br><br>
Key Functions for this section are:
* SDL_GetTicks()
* SDL_SetWindowTitle()<br>

***1d. Implement Frame Independent Movement.*** This involves calculating the delta time and passing it to ALL of our update functions so we can multiply our speed by the delta time. This should be done in your application loop and update functions.

**2. Refactoring our Rectangle Class to Sprite**

***2a.*** Rename your rectangle class to "Sprite". Make sure to replace all mentions to "Rectangle" to "Sprite", but make sure to not replace certain keywords that we need such as SDL_FRect.

***2b.*** Replace/Create a member variable called SDL_FRect(...) that has x, y, w, h set to 40.0f.

***2c.*** Create a "CreateSprite" method that takes in an SDL_Renderer and a file path. This method should load a .bmp file, create a texture, and randomize position and speed. It should **NOT** randomize size anymore.<br><br>
Key Functions:
* SDL_LoadBMP()
* SDL_CreateTextureFromSurface()

***2d.*** Modify your Sprite's Render function to render a texture, not a rectangle.<br><br>
Key Functions:
* SDL_RenderCopyF()

At a minimum, your Sprite class should have the following member variables. You may add more, and this assignment may require you to add more. You may or may not need to initialize the member variables.<br>
* SDL_FRect mSprite;
* float mSpeed;
* bool yPositiveDirection;
* bool xPositiveDirection;
* SDL_Texture* mTexture;
* SDL_Renderer* mRenderer;

**3. Application Class StartUp()**

Your application class should now implement frame capping, frame independent movement, and displaying frame rate in the window title.

Next, you'll need to create 30 enemy sprites with the provided Alien asset. You'll also need to create a main character sprite with the Spaceship asset. You no longer need to allow command-line arguments for how many rectangles should be rendered. 30 enemies, and 1 main character should be hard-coded into your program. Rendering the enemies should be pretty similar to rendering the rectangles from the previous assignment, but you'll need to make sure you call CreateSprite() before adding the enemy to your vector. Also, remember your main character sprite now needs to be updated and renderered in your main loop.

At a minimum, your Application class should have the following member variables. You may add more, and this assignment may require you to add more. You may or may not need to initialize the member variables.<br>
* std::vector<Sprite> mEnemies;
* Sprite mainCharacter;
* SDL_Window* mWindow;
* SDL_Renderer* mRenderer;
* bool mRun;

**Additional Tips**<br>
* There are a lot of small things to implement in this assignment. Take them one topic at a time, and one step at a time.
* Before implementing a function, make sure you look up the documentation for the function and understand what its required parameters are, and what it returns. You may have to cast variables to different types in order for the function to accept the parameter.
* I'd recommend writing out the steps for each section before implementing as it can help you see the bigger picture.

**No specifics required, but keep them reasonable**
* Window dimensions
* Rectangle movement velocity
* Rectangle spawn locations

**How to compile and run your program**

Your code may compile with different commands based on your architecture, but a sample compilation command may look like: g++ -std=c++20 ./src/*.cpp `pkg-config --cflags --libs sdl2` -o /bin/prog.

**Submission/Deliverables**

Submission

Commit all of your files to github, including any additional files you create.
Do not commit any binary files unless told to do so.
Do not commit any 'data' files generated when executing a binary.
Submit your GitHub link on Canvas.

Deliverables

You need to commit your code to this repository.

Q: Can I do more than is required?
A: Sure, have as much fun with it as you like!

Found a bug?

If you found a mistake (big or small, including spelling mistakes) in this lab, kindly send me an e-mail. It is not seen as nitpicky, but appreciated! (Or rather, future generations of students will appreciate it!)

**Goal** Your output doesn't have to be exactly as seen in the below video, but it should be pretty close.

![](../Media/Module05-Goal.mov)

