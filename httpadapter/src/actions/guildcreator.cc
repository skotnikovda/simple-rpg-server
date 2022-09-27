#include "httpadapter/actions/guildcreator.h"

#include <nlohmann/json.hpp>

#include "application/registry.h"
#include "httpadapter/converters/createguildrequest.h"
#include "httpadapter/utility/requesthandler.h"

namespace httpadapter {
Target GuildCreator::RequestTarget() { return Target("/api/createguild"); }
Response GuildCreator::Post(const Request& request) {
  auto creator = [](const Request& request) {
    using json = nlohmann::json;
    auto data = json::parse(request.body());
    auto create_request = CreateGuildRequest::ToType(data);
    auto service = application::Registry::GetService();
    service->CreateGuild(create_request);
    auto response = Response();
    response.set_code(ResponseStatus::kOk);
    return response;
  };
  auto handler =
      RequestHandler(creator).handleError<nlohmann::json::type_error>();
  auto response = handler.process(request);
  return response;
};
}  // namespace httpadapter
