#pragma once
#include "CoreMinimal.h"
#include "Interfaces/IHttpRequest.h"
#include "IWebSocket.h"

struct ZEKUMOSDK_API FZekumoError { int32 Status=0; FString Code; FString Message; };
DECLARE_DELEGATE_TwoParams(FZekumoResponse,const TSharedPtr<FJsonObject>&,const FZekumoError&);
DECLARE_MULTICAST_DELEGATE_TwoParams(FZekumoRealtimeEvent,const FString&,const TSharedPtr<FJsonValue>&);

class ZEKUMOSDK_API FZekumoClient:public TSharedFromThis<FZekumoClient> {
public:
 FZekumoClient(FString AppId,FString BaseUrl,FString Token=TEXT(""));
 void Request(const FString& Method,const FString& Path,const TSharedPtr<FJsonObject>& Body,FZekumoResponse Done,bool Auth=true);
 void LoginGuest(const FString& DeviceId,const FString& Nickname,FZekumoResponse Done);
 void LoginPassword(const FString& Username,const FString& Password,FZekumoResponse Done);
 void LoginTicket(const FString& Ticket,FZekumoResponse Done);
 void Register(const FString& Username,const FString& Password,const FString& Nickname,FZekumoResponse Done);
 void Get(const FString& Path,FZekumoResponse Done,bool Auth=true){Request(TEXT("GET"),Path,nullptr,Done,Auth);} void Post(const FString& Path,const TSharedPtr<FJsonObject>& Body,FZekumoResponse Done,bool Auth=true){Request(TEXT("POST"),Path,Body,Done,Auth);} void Put(const FString& Path,const TSharedPtr<FJsonObject>& Body,FZekumoResponse Done){Request(TEXT("PUT"),Path,Body,Done);} void Delete(const FString& Path,FZekumoResponse Done){Request(TEXT("DELETE"),Path,nullptr,Done);}
 void ConnectRealtime(); void SendRealtime(const FString& Type,const TSharedPtr<FJsonValue>& Data=nullptr); void CloseRealtime();
 FZekumoRealtimeEvent OnRealtimeEvent; FString GetToken()const{return Token;} void SetToken(FString Value){Token=MoveTemp(Value);} FString GetAppId()const{return AppId;}
 static FString Segment(const FString& Value);
private:
 FString AppId,BaseUrl,Token; TSharedPtr<IWebSocket> Socket;
 void Login(const FString& Path,const TSharedPtr<FJsonObject>& Body,FZekumoResponse Done);
};
