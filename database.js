const mysql = require('mysql2');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'root',
  password: 'hhh',
  database: 'mydb'
});
module.exports = connection;