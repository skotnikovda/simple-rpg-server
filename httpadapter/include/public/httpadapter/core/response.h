#pragma once

#include <boost/beast/http.hpp>
#include <string>

namespace httpadapter {
enum ResponseStatus {
  kOk = 200,
  kCreated = 201,
  kNotFound = 404,
  kConflict = 409,
  kBadRequest = 400,
  kInternalServerError = 500,
};
class Response {
 private:
  std::string body_;
  ResponseStatus code_;

 public:
  Response() {
    body_ = "";
    code_ = ResponseStatus::kNotFound;
  }
  std::string body() { return body_; }
  std::string set_body(const std::string &other_body) {
    body_ = other_body;
    return body_;
  }
  ResponseStatus code() { return code_; }
  ResponseStatus set_code(ResponseStatus code) {
    code_ = code;
    return code_;
  }
  operator boost::beast::http::response<boost::beast::http::string_body>() {
    namespace http = boost::beast::http;
    auto response = http::response<http::string_body>();
    response.body() = body_;
    response.result(code_);
    return response;
  }
};
}  // namespace httpadapter
