# Zekumo SDK for Unreal Engine 5

Copy this plugin into `Plugins/ZekumoSDK`. The runtime module provides an
asynchronous HTTP client, structured errors, auth helpers, token persistence,
and native WebSockets. All API routes are available through `Get`, `Post`,
`Put`, and `Delete`; path segments should use `Segment`. Realtime protocol
events are surfaced through `OnRealtimeEvent`, and room/chat commands use
`SendRealtime`. No app secret is stored in game clients. License: MIT.
