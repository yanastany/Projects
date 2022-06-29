﻿using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using ProjectV1.DAL.Models.Auth;
using ProjectV1.Services.AuthServices;

namespace ProjectV1.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class AuthController : ControllerBase
    {
        private readonly IAuthService _authService;

        public AuthController(IAuthService authService)
        {
            _authService = authService;
        }

        [HttpPost("register")]
        public async Task<IActionResult> Register(RegisterModel model) => Ok(await _authService.Register(model));

        [HttpPost("login")]
        public async Task<IActionResult> Login(LoginModel model) => Ok(await _authService.Login(model));

    }
}
