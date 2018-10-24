cmake_minimum_required(VERSION 3.10)
project(FightServer)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")#多线程需要的参数
include_directories(/usr/include/mysql)

find_package(Protobuf REQUIRED)
if(PROTOBUF_FOUND)
    message(STATUS "protobuf library found")
else()
    message(FATAL_ERROR "protobuf library is needed but cant be found")
endif()

include_directories(${PROTOBUF_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})



add_executable(FightServer main.cpp
        Net/Acceptor.cpp
        Net/Acceptor.h
        Net/Mboost.cpp
        Net/Mboost.h
        Net/Socket.cpp
        Net/Socket.h
        Net/TcpServer.cpp
        Net/TcpServer.h
        Net/Types.h
        Net/StringPiece.h
        Net/EventloopThread.cpp
        Net/EventloopThread.h
        Net/CurrentThread.h
        Net/Eventloop.cpp
        Net/Channel.cpp
        Net/Epollpoller.cpp
        Net/CurrentThread.h
        Net/EventloopThreadpool.cpp
        Net/EventloopThreadpool.h
        Net/inetAddress.cpp
        Net/Tcpcoonetion.cpp
        Net/TcpServer.cpp
        Net/Buffer.cpp
        commds.h
        intermediary.h
        Model/DataBase.h
        dbinteface/mysqlpool.h
        config.h
        base/MDatetime.cpp
        dbinteface/dbBase.h
        dbinteface/dbBase.cpp
        config.cpp
        Net/TimeQueue.cpp
        Net/Timer.cpp
        Net/Tcpclient.cpp
        Handler/BaseHandler.cpp
        Handler/Figth_initHandler.cpp
        protobuf_maegss/to_Fight.pb.cc
        Model/DataBase.cpp
        Model/AbsFight.cpp
        Model/Figth.cpp
        Model/FightBuild.cpp
        Model/Hero.cpp
        Model/Skills.cpp
        Model/Fightplay.cpp
        Handler/PlayinintHandelr.cpp)
target_link_libraries(FightServer libmysqlpp.so)#会在lib路径找到

target_link_libraries(FightServer ${PROTOBUF_LIBRARIES})
