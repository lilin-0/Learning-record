#题目编号
TITLE = 872

CXX         = g++
LFLAGS      = -std=c++17 -Wall -g

#引入头文件路径
INCPATH = -I ./ \

#所有源文件
SRC_CORE = $(TITLE).cpp

#生成目标文件
TARGET = a.out
TARGET : $(SRC_CORE)
	$(CXX) $(LFLAGS) $(SRC_CORE) $(INCPATH) -o $(TARGET)
	


clean:
	rm -rf a.out
	
