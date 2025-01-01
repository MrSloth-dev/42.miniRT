# miniRT

Raytracer with minilibx

TO-DO list
- [x] Parser
- [x] Chapter 1
- [x] Chapter 2
- [x] Chapter 3
- [x] Chapter 4
- [x] Chapter 5
- [x] Chapter 6
- [x] Chapter 7 - Scene
- [x] Chapter 8 - Shadows
- [x] Chapter 9 - Planes
- [x] Chapter 13 - Cylinders
- [x] Ivan - adjust specular and minimum light values 
        to never be in the dark, and accept different light colors in ambient
- [ ] Ivan - continue norminette and documentation.
- [ ] Ivan - do miro program scheme
- [ ] Ivan - do miro maths scheme
- [ ] Ivan - check for edge cases on ambient color.
- [ ] Norminette previous chapters 1 to 6(kinda) .
- [x] Make it work
- [ ] Make it robust
- [ ] Program name are "miniRT" ?
- [ ] Finish

PARSER ISSUES
- [x] Make parser great again
    - [ ] Again.
- [ ] Camera parser must be integrated with world and view transformation.
- [ ] cy 2.0,6.5,-1.50,-10 -0.2,0.0,0.7 3 2 0,255,0
        not valid, check if split has right number of parameters when splited
- [ ] block double vars on colors (0 - 255), only alow ints
- [ ] Limit Light,Ambient and Camera to 0 to 1
- [ ] After parse, need to copy ambient color and intensity to materials
- [ ] Ensure that program do not have leaks, or crash, if we don't have objects.
        Program must run, and show black window without any objects
- [ ] upgrade atod ft - better conversion (training only purposes, not priority
- [ ] file in folder like "teste/.rt" must NOT OPEN.
- [ ] on ft_check_syntax verify my comment
- [ ] argc must be "2"

At the end of project (or in advanced state)
- [ ] Remove wildcards from Makefile
- [ ] Reorganize Makefile sources.
