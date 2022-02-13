target_sources(SIOClient
    PUBLIC
        SIOClient.h  
        SIOClientImpl.h  
        SIOClientRegistry.h
        SIOEventRegistry.h
        SIOEventTarget.h
        SIONotificationHandler.h
        SIONotifications.h
        SIOPacket.h
)

target_include_directories(SIOClient
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)