#include "httpadapter/utility/defaultresponse.h"

namespace httpadapter {
Response DefaultResponse::MissingData() {
  auto response = Response();
  response.set_body("Missing required data");
  response.set_code(ResponseStatus::kBadRequest);
  return response;
}
Response DefaultResponse::ApplicationError() {
  auto response = Response();
  response.set_body("Application error");
  response.set_code(ResponseStatus::kInternalServerError);
  return response;
}
}  // namespace httpadapter
