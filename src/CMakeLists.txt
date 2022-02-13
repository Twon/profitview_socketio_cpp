add_library(SIOClient "")
target_sources(SIOClient
    PRIVATE
        SIOClient.cpp  
        SIOClientImpl.cpp  
        SIOClientRegistry.cpp
        SIOEventRegistry.cpp
        SIONotificationHandler.cpp
        SIOPacket.cpp
)

target_link_libraries(SIOClient
    PUBLIC 
        Poco::JSON
        OpenSSL::SSL
)

add_subdirectory(include)