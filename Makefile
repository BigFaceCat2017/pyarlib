
#Makefile generated by genmake.py (http://goanna.cs.rmit.edu.au/~pknowles/scripts.php)
#Known Bugs: Not all source files/headers of sublibs (projects with their own
#makefile in subdirectories) are searched. Hence, the external library prediction
#does not always get all results

#check x64
ASFX=
LBITS := $(shell getconf LONG_BIT)
ifeq ($(LBITS),64)
ASFX=64
endif

NOOP = @$(SHELL) -c true


.PHONY=all,debug,prof,opt,clean,cleaner,echodeps
TARGET=pyarlib$(ASFX).a
CC=g++
LD=ar
CFLAGS_R?=
CFLAGS= $(CFLAGS_R) -fpch-preprocess -Wno-unused-parameter -Wno-unused-but-set-variable `sdl2-config --cflags` `pkg-config freetype2 --cflags` -std=c++0x -Wall -Wextra -D_GNU_SOURCE -Wfatal-errors -Winvalid-pch
CFLAGS+= -Imesh/lib3ds/../
CFLAGS+= -Imesh/openctm/../
CFLAGS+= -Imesh/simpleobj/../
LFLAGS= -rcs 
SUBLIBS= mesh/lib3ds/lib3ds$(ASFX).a mesh/openctm/libopenctm$(ASFX).a mesh/simpleobj/libsimpleobj$(ASFX).a
OBJECTS= ./pugixml.o ./text.o ./camera.o ./guifps.o ./matrix.o prec.h.gch ./jeltzgui.o ./shaderutil.o ./vbomesh.o ./meshctm.o ./fileutil.o ./material.o ./profile.o ./config.o ./meshobj.o ./atlas.o ./img.o ./gpu.o ./thread.o ./kdtree.o ./trace.o ./benchmark.o ./quickgui.o ./texture.o ./quaternion.o ./vec.o ./immediate.o ./meshifs.o ./png_loader.o ./jeltzfly.o ./jeltz.o ./shaderbuild.o ./imgpng.o ./util.o ./matstack.o ./resources.o ./rtree.o ./mesh3ds.o ./ninebox.o ./scene.o ./findfile.o ./shader.o

all: meshlibdslibdsa meshopenctmlibopenctma meshsimpleobjlibsimpleobja $(TARGET)

debug: CFLAGS+= -g
debug: export CFLAGS_R+= -g
debug: all

prof: CFLAGS+= -pg
prof: export CFLAGS_R+= -pg
prof: all

opt: CFLAGS+= -03
opt: export CFLAGS_R+= -03
opt: all

ALL_SUBLIBS= $(SUBLIBS)
SUBSUBLIBS_MESHLIBDSLIBDSA= $(shell make echodeps --no-print-directory -C mesh/lib3ds/ 2>/dev/null)
ALL_SUBLIBS+= $(SUBSUBLIBS_MESHLIBDSLIBDSA:%.a=mesh/lib3ds/%.a)
SUBSUBLIBS_MESHOPENCTMLIBOPENCTMA= $(shell make echodeps --no-print-directory -C mesh/openctm/ 2>/dev/null)
ALL_SUBLIBS+= $(SUBSUBLIBS_MESHOPENCTMLIBOPENCTMA:%.a=mesh/openctm/%.a)
SUBSUBLIBS_MESHSIMPLEOBJLIBSIMPLEOBJA= $(shell make echodeps --no-print-directory -C mesh/simpleobj/ 2>/dev/null)
ALL_SUBLIBS+= $(SUBSUBLIBS_MESHSIMPLEOBJLIBSIMPLEOBJA:%.a=mesh/simpleobj/%.a)


#prints a list of library dependencies recursively
echodeps:
	@type normpath >/dev/null && normpath $(ALL_SUBLIBS) || echo $(ALL_SUBLIBS)


#linking/archiving the target
$(TARGET): $(SUBLIBS) $(OBJECTS)
	@echo linking $(TARGET)
	@$(LD) -o $(TARGET) $(OBJECTS) $(ALL_SUBLIBS) $(LFLAGS)

#target dependent libraries
mesh/lib3ds/lib3ds$(ASFX).a:
	$(NOOP) #just so $(ASFX) doesnt cause makefile complaints
meshlibdslibdsa:
	@$(MAKE) --no-print-directory -C mesh/lib3ds -q || ( echo +mesh/lib3ds && $(MAKE) --no-print-directory -C mesh/lib3ds && echo -mesh/lib3ds )
mesh/openctm/libopenctm$(ASFX).a:
	$(NOOP) #just so $(ASFX) doesnt cause makefile complaints
meshopenctmlibopenctma:
	@$(MAKE) --no-print-directory -C mesh/openctm -q || ( echo +mesh/openctm && $(MAKE) --no-print-directory -C mesh/openctm && echo -mesh/openctm )
mesh/simpleobj/libsimpleobj$(ASFX).a:
	$(NOOP) #just so $(ASFX) doesnt cause makefile complaints
meshsimpleobjlibsimpleobja:
	@$(MAKE) --no-print-directory -C mesh/simpleobj -q || ( echo +mesh/simpleobj && $(MAKE) --no-print-directory -C mesh/simpleobj && echo -mesh/simpleobj )

#compile object files
%.o : %.cpp
	@echo compiling $@ $(CFLAGS_R)
	@export CCACHE_DISABLE=1 && $(CC) $(CFLAGS) -c $< -o $@

#precompiled header
prec.h.gch: prec.cpp includegl.h prec.h
	@echo compiling $@ $(CFLAGS_R)
	@export CCACHE_DISABLE=1 && $(CC) $(CFLAGS) -c prec.h -o $@

#object dependencies
./pugixml.o: pugixml.cpp includegl.h pugiconfig.h pugixml.h prec.h prec.h.gch
./text.o: text.cpp config.h text.vert resources.h findfile.h text.frag shaderbuild.h fileutil.h text.geom vec.h shader.h img.h gpu.h includegl.h text.h embed.h util.h imgpng.h shaderutil.h prec.h matrix.h prec.h.gch
./camera.o: camera.cpp includegl.h camera.h matrix.h quaternion.h util.h vec.h prec.h prec.h.gch
./guifps.o: guifps.cpp shaderbuild.h ninebox.h matstack.h vec.h shader.h gpu.h includegl.h immediate.h guifps.h text.h quickgui.h atlas.h prec.h matrix.h prec.h.gch
./matrix.o: matrix.cpp includegl.h vec.h matrix.h prec.h prec.h.gch
./jeltzgui.o: jeltzgui.cpp jeltzgui.h shaderbuild.h vec.h jeltz.h texture.h gpu.h includegl.h immediate.h guifps.h matstack.h util.h ninebox.h prec.h config.h profile.h findfile.h atlas.h shader.h matrix.h quickgui.h text.h prec.h.gch
./shaderutil.o: shaderutil.cpp quaternion.h vec.h shader.h includegl.h camera.h matrix.h shaderbuild.h util.h shaderutil.h prec.h prec.h.gch
./vbomesh.o: vbomesh.cpp findfile.h fileutil.h vec.h gpu.h vbomesh.h includegl.h shader.h matrix.h shaderbuild.h material.h util.h shaderutil.h prec.h loader.h prec.h.gch
./meshctm.o: meshctm.cpp findfile.h fileutil.h vec.h gpu.h vbomesh.h includegl.h shader.h matrix.h shaderbuild.h material.h meshctm.h prec.h loader.h prec.h.gch
./fileutil.o: fileutil.cpp includegl.h prec.h prec.h.gch
./material.o: material.cpp vec.h shader.h img.h includegl.h matrix.h shaderbuild.h material.h util.h imgpng.h shaderutil.h prec.h prec.h.gch
./profile.o: profile.cpp includegl.h profile.h matrix.h shaderbuild.h util.h vec.h shader.h prec.h prec.h.gch
./config.o: config.cpp config.h resources.h default.cfg includegl.h embed.h prec.h prec.h.gch
./meshobj.o: meshobj.cpp findfile.h fileutil.h vec.h gpu.h img.h mesh/simpleobj/obj.h includegl.h shader.h matrix.h shaderbuild.h material.h util.h vbomesh.h imgpng.h meshobj.h prec.h loader.h prec.h.gch
./atlas.o: atlas.cpp gpu.h resources.h findfile.h atlas.h shaderbuild.h fileutil.h vec.h atlasBlit.frag shader.h img.h vbomesh.h includegl.h matrix.h embed.h util.h atlasBlit.vert imgpng.h shaderutil.h prec.h loader.h prec.h.gch
./img.o: img.cpp includegl.h img.h util.h vec.h prec.h prec.h.gch
./gpu.o: gpu.cpp vec.h gpu.h shader.h includegl.h matrix.h shaderbuild.h util.h shaderutil.h prec.h prec.h.gch
./thread.o: thread.cpp includegl.h thread.h prec.h prec.h.gch
./kdtree.o: kdtree.cpp util.h vec.h includegl.h prec.h kdtree.h prec.h.gch
./trace.o: trace.cpp findfile.h rtree.h shaderbuild.h fileutil.h vec.h thread.h gpu.h img.h vbomesh.h includegl.h shader.h camera.h matrix.h quaternion.h material.h util.h trace.h imgpng.h prec.h loader.h prec.h.gch
./benchmark.o: benchmark.cpp benchmark.h profile.h includegl.h util.h vec.h prec.h prec.h.gch
./quickgui.o: quickgui.cpp config.h ninebox.h matstack.h vec.h shader.h gpu.h includegl.h immediate.h prec.h quickgui.h shaderbuild.h util.h atlas.h text.h texture.h matrix.h prec.h.gch
./texture.o: texture.cpp includegl.h texture.h util.h vec.h imgpng.h prec.h img.h prec.h.gch
./quaternion.o: quaternion.cpp includegl.h vec.h prec.h quaternion.h matrix.h prec.h.gch
./vec.o: vec.cpp includegl.h vec.h prec.h prec.h.gch
./immediate.o: immediate.cpp resources.h shaderbuild.h vec.h shader.h embed.h gpu.h includegl.h immediate.h matrix.h matstack.h immediate.vert prec.h immediate.frag prec.h.gch
./meshifs.o: meshifs.cpp findfile.h fileutil.h vec.h gpu.h img.h vbomesh.h includegl.h shader.h meshifs.h matrix.h shaderbuild.h material.h util.h imgpng.h prec.h loader.h prec.h.gch
./png_loader.o: png_loader.cpp includegl.h png_loader.h prec.h prec.h.gch
./jeltzfly.o: jeltzfly.cpp shaderbuild.h vec.h jeltz.h shader.h includegl.h jeltzfly.h camera.h matrix.h quaternion.h util.h prec.h prec.h.gch
./jeltz.o: jeltz.cpp includegl.h matrix.h shaderbuild.h util.h vec.h jeltz.h shader.h prec.h prec.h.gch
./shaderbuild.o: shaderbuild.cpp includegl.h findfile.h shaderbuild.h fileutil.h util.h vec.h prec.h prec.h.gch
./imgpng.o: imgpng.cpp includegl.h prec.h util.h vec.h imgpng.h img.h prec.h.gch
./util.o: util.cpp includegl.h matrix.h quaternion.h util.h vec.h prec.h prec.h.gch
./matstack.o: matstack.cpp includegl.h vec.h prec.h matstack.h matrix.h prec.h.gch
./resources.o: resources.cpp includegl.h resources.h resourcedefs.h embed.h prec.h prec.h.gch
./rtree.o: rtree.cpp includegl.h rtree.h util.h vec.h prec.h prec.h.gch
./mesh3ds.o: mesh3ds.cpp shaderbuild.h findfile.h fileutil.h mesh3ds.h vec.h gpu.h img.h vbomesh.h includegl.h shader.h matrix.h matstack.h material.h util.h imgpng.h mesh/lib3ds/lib3ds.h prec.h loader.h prec.h.gch
./ninebox.o: ninebox.cpp resources.h ninebox.h shaderbuild.h vec.h ninebox.vert gpu.h shader.h includegl.h prec.h embed.h util.h atlas.h ninebox.frag texture.h matrix.h prec.h.gch
./scene.o: scene.cpp matstack.h fileutil.h vec.h jeltz.h scene.h shader.h includegl.h immediate.h quaternion.h util.h atlas.h vbomesh.h meshobj.h prec.h config.h findfile.h ninebox.h gpu.h shaderbuild.h camera.h matrix.h quickgui.h loader.h text.h prec.h.gch
./findfile.o: findfile.cpp config.h includegl.h findfile.h prec.h fileutil.h prec.h.gch
./shader.o: shader.cpp config.h findfile.h fileutil.h vec.h shader.h includegl.h matrix.h shaderbuild.h util.h prec.h prec.h.gch

#clean and cleaner
clean:
	@echo cleaning $(TARGET)
	@rm -f $(OBJECTS)
	@rm -f $(TARGET)
	@rm -f prec.h.gch
cleaner: clean
	@echo +mesh/lib3ds
	@$(MAKE) cleaner --no-print-directory -C mesh/lib3ds
	@echo -mesh/lib3ds
	@echo +mesh/openctm
	@$(MAKE) cleaner --no-print-directory -C mesh/openctm
	@echo -mesh/openctm
	@echo +mesh/simpleobj
	@$(MAKE) cleaner --no-print-directory -C mesh/simpleobj
	@echo -mesh/simpleobj









