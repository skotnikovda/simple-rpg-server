#include "httpadapter/actions/charactergetter.h"

#include "application/registry.h"
#include "httpadapter/converters/accesstoken.h"
#include "httpadapter/converters/character.h"
#include "httpadapter/utility/requesthandler.h"

namespace httpadapter {
Target CharacterGetter::RequestTarget() {
  return std::string("/api/character");
}
Response CharacterGetter::Post(const Request& request) {
  auto getter = [](const Request& request) {
    using json = nlohmann::json;
    auto data = json::parse(request.body());
    auto token = AccessToken::ToType(data);
    auto service = application::Registry::GetService();
    auto character = service->GetCharacter(token);
    auto response = Response();
    response.set_code(ResponseStatus::kOk);
    response.set_body(Character::ToJson(character).dump());
    return response;
  };
  auto handler =
      RequestHandler(getter).handleError<nlohmann::json::type_error>();
  auto response = handler.process(request);
  return response;
}
}  // namespace httpadapter
