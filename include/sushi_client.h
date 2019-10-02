/**
 * @file sushi_client.h
 * @author Ruben Svensson (therubething@gmail.com)
 * @brief maker for the sushi client
 * @version 0.1
 * @date 2019-09-27
 * 
 * @copyright MIND Music Labs AB, Stockholm, Sweden 2019
 * 
 */

#ifndef SUSHI_CLIENT_H
#define SUSHI_CLIENT_H

#include <memory>
#include <string>

#include "control_interface.h"

namespace sushi_controller
{
constexpr char DEFAULT_ADDRESS[] = "localhost::51051";
std::unique_ptr<sushi_controller::SushiControl> CreateSushiController(const std::string& server_address = DEFAULT_ADDRESS);

} //sushi_controller

#endif //SUSHI_CLIENT_H