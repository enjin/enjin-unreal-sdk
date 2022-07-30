# Blockchain SDK by Enjin for Unreal Engine

Create blockchain projects and video games using Unreal Engine.

[Learn more](https://enjin.io/) about the Enjin blockchain platform.

Sign up to Enjin Cloud: [Goerli (Testnet)](https://goerli.cloud.enjin.io/),
[Mainnet (Production)](https://cloud.enjin.io/), or [JumpNet](https://jumpnet.cloud.enjin.io/).

### Resources

* [Enjin Docs](https://docs.enjin.io/enjin-platform-sdks/introduction-to-enjin-platform-sdks)

### Support

Contact Enjin support through email at support@enjin.io or submit a ticket at https://enjin.io/support.

### Table of Contents

* [Compatibility](#compatibility)
    * [Platform Schemas](#platform-schemas)
    * [Unreal Engine](#unreal-engine)
* [Usage](#usage)
    * [Async Operations](#async-operations)
* [Quick Start](#quick-start)

## Compatibility

### Platform Schemas

This SDK provides an API compatible with the V.2 schemas used on the Enjin Platform.

### Unreal Engine

This SDK supports Unreal Engine 4.27 and Unreal Engine 5.

This SDK utilizes C++14 as its standard version.

## Usage

### Async Operations

Asynchronous operations performed by this SDK, such as HTTP requests and event processing via websockets, may not
necessarily run on the Game Thread. As such, it is necessary to resynchronize when passing data to objects that are
interacted with on the Game Thread, such as those in the Slate UI framework.

## Quick Start

The below example shows how to setup and authenticate a player client for the player schema.

NOTE: `AccessToken` is expected to be retrieved from a game server connected as a project client to the Enjin Platform.
This is to help keep the project's authentication credentials secured.

```c++
#include "EnjinHosts.h"
#include "PlayerClient.h"
#include "Model/AccessToken.h"

using namespace Enjin::Sdk;
using namespace Enjin::Sdk::Model;

// Withing the source file of an actor
void AExampleProject::BeginPlay()
{
    Super::BeginPlay();

    // Builds the player client to run on the Goerli test network.
    // See: https://goerli.cloud.enjin.io to sign up for the test network.
    // Client is a class member-field of type TUniquePtr<FPlayerClient>.
    Client = FPlayerClient::Builder()
        .BaseUrl(FEnjinHosts::Goerli())
        .Build();

    FAccessToken AccessToken = /* Retrieved from a game server. */;

    // Authenticates the client with the access token.
    Client->Auth(AccessToken.GetToken().GetValue());

    // Checks if the client was authenticated.
    if (Client->IsAuthenticated())
    {
        UE_LOG(LogTemp, Display, TEXT("Client is now authenticated"));
    }
    else
    {
        UE_LOG(LogTemp, Display, TEXT("Client was not authenticated"));
    }
}
```

For immediate setup and testing, a project client that has access to project schema requests may be setup in the game
instance as shown below.

This is **NOT** recommended for anything beyond internal testing, due to possible exposure of the project's credentials
and the game instance ought to be setup to use a player client as soon as possible.

```c++
#include "EnjinHosts.h"
#include "GraphQlResponse.h"
#include "ProjectClient.h"
#include "Model/AccessToken.h"
#include "Project/AuthProject.h"

using namespace Enjin::Sdk;
using namespace Enjin::Sdk::GraphQl;
using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Project;

// Withing the source file of an actor
void AExampleProject::BeginPlay()
{
    Super::BeginPlay();

    // Builds the project client to run on the Goerli test network.
    // See: https://goerli.cloud.enjin.io to sign up for the test network.
    // Client is a class member-field of type TUniquePtr<FProjectClient>.
    Client = FProjectClient::Builder()
        .BaseUrl(FEnjinHosts::Goerli())
        .Build();

    // Creates the request to authenticate the client.
    // Replace the appropriate strings with the project's UUID and secret.
    FAuthProject Req = FAuthProject()
        .SetUuid(TEXT("<the-project's-uuid>"))
        .SetSecret(TEXT("<the-project's-secret>"));

    // Sends the request to the platform and gets the response.
    Client->AuthProject(Req).Next([this](TGraphQlResponseForOnePtr<FAccessToken> Res)
    {
        if (!Res.IsValid() || !Res->IsSuccessful())
        {
            UE_LOG(LogTemp, Display, TEXT("AuthProject request failed"));
            return;
        }

        // Authenticates the client with the access token.
        Client->Auth(Res->GetResult().GetValue().GetToken().GetValue());

        // Checks if the client was authenticated.
        if (Client->IsAuthenticated())
        {
            UE_LOG(LogTemp, Display, TEXT("Client is now authenticated"));
        }
        else
        {
            UE_LOG(LogTemp, Display, TEXT("Client was not authenticated"));
        }
    });
}
```
