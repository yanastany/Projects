﻿using Microsoft.EntityFrameworkCore.Migrations;

namespace ProjectV1.DAL.Migrations
{
    public partial class Contract_Player_Staff_Migration_2 : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.RenameColumn(
                name: "Surname",
                table: "Players",
                newName: "LastName");

            migrationBuilder.RenameColumn(
                name: "Name",
                table: "Players",
                newName: "FirstName");
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.RenameColumn(
                name: "LastName",
                table: "Players",
                newName: "Surname");

            migrationBuilder.RenameColumn(
                name: "FirstName",
                table: "Players",
                newName: "Name");
        }
    }
}
