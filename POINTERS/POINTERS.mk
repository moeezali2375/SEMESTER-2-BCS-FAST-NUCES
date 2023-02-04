##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=POINTERS
ConfigurationName      :=Debug
WorkspacePath          :=/Users/moeezali/Documents/VS/SEMESTER#2/POINTERS
ProjectPath            :=/Users/moeezali/Documents/VS/SEMESTER#2/POINTERS
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Moeez Ali
Date                   :=24/02/2022
CodeLitePath           :="/Users/moeezali/Library/Application Support/CodeLite"
LinkerName             :=/usr/bin/clang++
SharedObjectLinkerName :=/usr/bin/clang++ -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="POINTERS.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -O0
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch). $(LibraryPathSwitch)Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/clang++
CC       := /usr/bin/clang
CXXFLAGS :=  -g -Wall $(Preprocessors)
CFLAGS   :=   $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/findmin.cpp$(ObjectSuffix) $(IntermediateDirectory)/1.cpp$(ObjectSuffix) $(IntermediateDirectory)/pointers_arrays.cpp$(ObjectSuffix) $(IntermediateDirectory)/pointers.cpp$(ObjectSuffix) $(IntermediateDirectory)/assignvaluetest.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)


$(IntermediateDirectory)/.d:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/findmin.cpp$(ObjectSuffix): findmin.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/findmin.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/findmin.cpp$(DependSuffix) -MM findmin.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/moeezali/Documents/VS/SEMESTER#2/POINTERS/findmin.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/findmin.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/findmin.cpp$(PreprocessSuffix): findmin.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/findmin.cpp$(PreprocessSuffix) findmin.cpp

$(IntermediateDirectory)/1.cpp$(ObjectSuffix): 1.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/1.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/1.cpp$(DependSuffix) -MM 1.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/moeezali/Documents/VS/SEMESTER#2/POINTERS/1.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/1.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/1.cpp$(PreprocessSuffix): 1.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/1.cpp$(PreprocessSuffix) 1.cpp

$(IntermediateDirectory)/pointers_arrays.cpp$(ObjectSuffix): pointers_arrays.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/pointers_arrays.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/pointers_arrays.cpp$(DependSuffix) -MM pointers_arrays.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/moeezali/Documents/VS/SEMESTER#2/POINTERS/pointers_arrays.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pointers_arrays.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/pointers_arrays.cpp$(PreprocessSuffix): pointers_arrays.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/pointers_arrays.cpp$(PreprocessSuffix) pointers_arrays.cpp

$(IntermediateDirectory)/pointers.cpp$(ObjectSuffix): pointers.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/pointers.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/pointers.cpp$(DependSuffix) -MM pointers.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/moeezali/Documents/VS/SEMESTER#2/POINTERS/pointers.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pointers.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/pointers.cpp$(PreprocessSuffix): pointers.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/pointers.cpp$(PreprocessSuffix) pointers.cpp

$(IntermediateDirectory)/assignvaluetest.cpp$(ObjectSuffix): assignvaluetest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/assignvaluetest.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/assignvaluetest.cpp$(DependSuffix) -MM assignvaluetest.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/moeezali/Documents/VS/SEMESTER#2/POINTERS/assignvaluetest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/assignvaluetest.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/assignvaluetest.cpp$(PreprocessSuffix): assignvaluetest.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/assignvaluetest.cpp$(PreprocessSuffix) assignvaluetest.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


