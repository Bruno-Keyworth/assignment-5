Assignment-5:
	g++-11 main.cpp Nucleus.cpp StableNucleus.cpp RadioactiveNucleus.cpp Particle.cpp Electron.cpp Photon.cpp function.cpp -o Assignment-5.o -std=gnu++17

clean:
	rm Assignment-5.o

run:
	g++-11 main.cpp Nucleus.cpp StableNucleus.cpp RadioactiveNucleus.cpp Particle.cpp Electron.cpp Photon.cpp functions.cpp -o Assignment-5.o -std=gnu++17
	./Assignment-5.o
