TEMPLATE 	= Makefile.template
OUTPUT 		= Makefile
CXX 		= g++
CXXFLAGS 	= -std=c++17

task:
	@echo "Setting up $(problem)"
	mkdir $(problem)
	cp template.cpp $(problem)/$(problem).cpp
	touch $(problem)/input.txt
	touch $(problem)/output.txt
	@echo "Generating $(problem) Makefile from $(TEMPLATE)..."
	sed \
		-e 's/@CXX@/$(CXX)/g' \
		-e 's/@CXXFLAGS@/$(CXXFLAGS)/g' \
		-e 's/@problem@/$(problem)/g' \
		$(TEMPLATE) > $(problem)/$(OUTPUT)